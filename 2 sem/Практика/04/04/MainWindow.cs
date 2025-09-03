using System;
using System.Collections.Generic;
using System.IO;
using GLib;
using Gtk;
using Application = Gtk.Application;
using UI = Gtk.Builder.ObjectAttribute;

namespace _04;

class MainWindow : Window
{
    private readonly List<Entrance> _data = new List<Entrance>();

    private readonly ListStore _model = new(
        typeof(string),
        typeof(string),
        typeof(int),
        typeof(string)
    );

    private bool _searchByDate;
    private string _startDate = "";
    private string _endDate = "";
    private string _searchName = "";
    private string _searchCountry = "";

    [UI] private Statusbar _statusBar;
    [UI] private TreeView _treeView;

    [UI] private Button _btnOpen;
    [UI] private Button _btnSave;
    [UI] private Button _btnAdd;
    [UI] private Button _btnEdit;
    [UI] private Button _btnDelete;
    [UI] private Button _btnSearch;
    [UI] private Button _btnClearSearch;

    public MainWindow() : this(new Builder("MainWindow.glade"))
    {
        _treeView.Model = _model;
        CreateColumns();
        ReadFromFile();
    }

    private MainWindow(Builder builder) : base(builder.GetRawOwnedObject("MainWindow"))
    {
        builder.Autoconnect(this);

        DeleteEvent += Window_DeleteEvent;
    }

    private void CreateColumns()
    {
        string[] names = { "Наименование", "Дата поступления", "Количество", "Страна-производитель" };
        for (var i = 0; i < names.Length; i++)
        {
            var cellRendererText = new CellRendererText();
            var column = new TreeViewColumn(names[i], cellRendererText, "text", i);
            column.SortColumnId = i;
            _treeView.AppendColumn(column);
        }
    }

    private void Window_DeleteEvent(object sender, DeleteEventArgs a)
    {
        Application.Quit();
    }

    private void ShowMessage(string message)
    {
        const int timeout = 3000;
        var messageId = _statusBar.Push(0, message);
        Timeout.Add(timeout, () =>
        {
            _statusBar.Remove(0, messageId);
            return false; // Останавливаем таймер
        });
    }

    private int GetSelected()
    {
        var treePaths = _treeView.Selection.GetSelectedRows();
        if (treePaths.Length == 0 || treePaths[0].Indices.Length == 0)
            return -1;
        return treePaths[0].Indices[0];
    }

    private void OnOpenClicked(object sender, EventArgs e)
    {
        _data.Clear();
        ReadFromFile();
    }

    private void OnSaveClicked(object sender, EventArgs e)
    {
        WriteToFile();
    }

    protected void OnAddClicked(object sender, EventArgs e)
    {
        var dialog = new AddDialog(this);
        if (dialog.Run() == (int)ResponseType.Ok)
        {
            var newEntrance = dialog.GetEntrance();
            _data.Add(newEntrance);
            _model.AppendValues(newEntrance.Name, newEntrance.Date, newEntrance.Amount, newEntrance.Country);
        }

        dialog.Destroy();
    }

    private void OnEditClicked(object sender, EventArgs e)
    {
        var selected = GetSelected();
        if (selected == -1)
        {
            ShowMessage("Не выбрана строка для изменения!");
            return;
        }

        var dialog = new AddDialog(this, _data[selected]);
        if (dialog.Run() == (int)ResponseType.Ok)
        {
            _data[selected] = dialog.GetEntrance();
            UpdateTable();
        }

        dialog.Destroy();
    }

    private void OnDeleteClicked(object sender, EventArgs e)
    {
        var selected = GetSelected();
        if (selected == -1)
        {
            ShowMessage("Не выбрана строка для удаления!");
            return;
        }

        _data.RemoveAt(selected);
        UpdateTable();
    }

    private void OnSearchClicked(object sender, EventArgs e)
    {
        var dialog = new SearchDialog(this);
        dialog.SearchName = _searchName;
        dialog.SearchCountry = _searchCountry;
        dialog.SearchByDate = _searchByDate;
        dialog.StartDate = _startDate;
        dialog.EndDate = _endDate;

        if (dialog.Run() == (int)ResponseType.Ok)
        {
            _searchName = dialog.SearchName;
            _searchCountry = dialog.SearchCountry;
            _searchByDate = dialog.SearchByDate;
            if (_searchByDate)
            {
                _startDate = dialog.StartDate;
                _endDate = dialog.EndDate;
            }
            else
            {
                _startDate = "";
                _endDate = "";
            }

            UpdateTable();
        }

        dialog.Destroy();
    }

    private void OnClearSearchClicked(object sender, EventArgs e)
    {
        _searchByDate = false;
        _searchName = "";
        _searchCountry = "";
        UpdateTable();
    }

    private bool CompareDates(string date1, string date2) // true if date1 <= date2
    {
        var values1 = date1.Split('/');
        var values2 = date2.Split('/');
        int[] i1 = { int.Parse(values1[0]), int.Parse(values1[1]), int.Parse(values1[2]) };
        int[] i2 = { int.Parse(values2[0]), int.Parse(values2[1]), int.Parse(values2[2]) };
        if (i1[2] != i2[2])
            return i1[2] < i2[2];
        if (i1[1] != i2[1])
            return i1[1] < i2[1];
        return i1[0] <= i2[0];
    }

    private void UpdateTable()
    {
        _model.Clear();
        foreach (var entrance in _data)
        {
            if (entrance.Name.Contains(_searchName) && entrance.Country.Contains(_searchCountry))
            {
                if (!_searchByDate ||
                    (_searchByDate && CompareDates(_startDate, entrance.Date) &&
                     CompareDates(entrance.Date, _endDate)))
                    _model.AppendValues(entrance.Name, entrance.Date, entrance.Amount, entrance.Country);
            }
        }
    }

    private void ReadFromFile()
    {
        try
        {
            var streamReader = new StreamReader("data.txt");
            var lines = streamReader.ReadToEnd().Split('\n');
            for (var i = 0; i < lines.Length / 4; i++)
            {
                var newEntrance = new Entrance
                {
                    Name = lines[i * 4],
                    Date = lines[i * 4 + 1],
                    Amount = int.Parse(lines[i * 4 + 2]),
                    Country = lines[i * 4 + 3]
                };
                _data.Add(newEntrance);
            }

            streamReader.Close();
            ShowMessage($"Прочитано строк: {lines.Length / 4}");
            UpdateTable();
        }
        catch (Exception)
        {
            ShowMessage("Ошибка при чтении файла!");
        }
    }

    private void WriteToFile()
    {
        try
        {
            var streamWriter = new StreamWriter("data.txt");
            foreach (var entrance in _data)
            {
                streamWriter.WriteLine(entrance.Name);
                streamWriter.WriteLine(entrance.Date);
                streamWriter.WriteLine(entrance.Amount);
                streamWriter.WriteLine(entrance.Country);
            }

            streamWriter.Close();
            ShowMessage("Записано строк: " + _data.Count);
        }
        catch (Exception)
        {
            ShowMessage("Ошибка при записи файла!");
        }
    }
}