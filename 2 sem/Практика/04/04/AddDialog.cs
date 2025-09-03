using System;
using Gtk;
using UI = Gtk.Builder.ObjectAttribute;

namespace _04;

public class AddDialog : Dialog
{
    [UI] private Entry _edtName;
    [UI] private Entry _edtCountry;

    [UI] private SpinButton _spnAmount;
    [UI] private SpinButton _spnDay;
    [UI] private SpinButton _spnMonth;
    [UI] private SpinButton _spnYear;

    public AddDialog(Window parent, Entrance editEntrance) : this(parent)
    {
        _edtName.Text = editEntrance.Name;
        
        var date = editEntrance.Date.Split("/");
        _spnDay.Text = date[0];
        _spnMonth.Text = date[1];
        _spnYear.Text = date[2];
        
        _spnAmount.Value = editEntrance.Amount;
        _edtCountry.Text = editEntrance.Country;

        Title = "Изменить запись";
    }

    public AddDialog(Window parent) : this(parent, new Builder("AddDialog.glade"))
    {
        // Настройка SpinButtons
        _spnAmount.SetRange(1, double.MaxValue);
        _spnAmount.SetIncrements(1, 1);
        _spnAmount.Value = 1;

        _spnDay.SetRange(1, 31);
        _spnDay.SetIncrements(1, 1);
        _spnDay.Value = 1;

        _spnMonth.SetRange(1, 12);
        _spnMonth.SetIncrements(1, 1);
        _spnMonth.Value = 1;

        _spnYear.SetRange(1970, 2025);
        _spnYear.SetIncrements(1, 1);
        _spnYear.Value = 2025;
    }

    private AddDialog(Window parent, Builder builder) : base(builder.GetRawObject("AddDialog"))
    {
        var dialog = (Dialog)builder.GetObject("AddDialog");
        dialog.TransientFor = parent;
        dialog.Modal = true;
        builder.Autoconnect(this);
    }

    public Entrance GetEntrance()
    {
        return new Entrance
        {
            Name = _edtName.Text,
            Date = $"{_spnDay.Value}/{_spnMonth.Value}/{_spnYear.Value}",
            Amount = (int)_spnAmount.Value,
            Country = _edtCountry.Text
        };
    }

    private void ShowMessage(string message)
    {
        var md = new MessageDialog(
            this,
            DialogFlags.Modal,
            MessageType.Error,
            ButtonsType.Ok,
            message
        )
        {
            Title = "Ошибка!"
        };

        md.Run();
        md.Destroy();
    }

    private void OnOkButtonClicked(object sender, EventArgs e)
    {
        if (_edtName.Text == "")
        {
            ShowMessage("Наименование не может быть пустым!");
            _edtName.HasFocus = true;
            return;
        }
        if (_edtCountry.Text == "")
        {
            ShowMessage("Страна производитель не может быть пустой!");
            _edtCountry.HasFocus = true;
            return;
        }
        Respond(ResponseType.Ok);
    }

    private void OnCancelButtonClicked(object sender, EventArgs e)
    {
        Respond(ResponseType.Cancel);
    }
}