using System;
using System.Linq;
using Gtk;
using UI = Gtk.Builder.ObjectAttribute;

namespace _04;

public class SearchDialog : Dialog
{
    [UI] private Entry _edtName;
    [UI] private Entry _edtCountry;

    [UI] private CheckButton _chkSearchByDate;

    [UI] private SpinButton _spnStartDay;
    [UI] private SpinButton _spnStartMonth;
    [UI] private SpinButton _spnStartYear;
    [UI] private SpinButton _spnEndDay;
    [UI] private SpinButton _spnEndMonth;
    [UI] private SpinButton _spnEndYear;

    public string SearchName
    {
        get => _edtName.Text;
        set => _edtName.Text = value;
    }

    public string SearchCountry
    {
        get => _edtCountry.Text;
        set => _edtCountry.Text = value;
    }

    public bool SearchByDate
    {
        get => _chkSearchByDate.Active;
        set
        {
            _chkSearchByDate.Active = value;
            SetSpnSensitive(value);
        }
    }

    public string StartDate
    {
        get => $"{_spnStartDay.Value}/{_spnStartMonth.Value}/{_spnStartYear.Value}";
        set
        {
            if (value == "") return;
            var values = value.Split("/");
            _spnStartDay.Value = int.Parse(values[0]);
            _spnStartMonth.Value = int.Parse(values[1]);
            _spnStartYear.Value = int.Parse(values[2]);
        }
    }

    public string EndDate
    {
        get => $"{_spnEndDay.Value}/{_spnEndMonth.Value}/{_spnEndYear.Value}";
        set
        {
            if (value == "") return;
            var values = value.Split("/");
            _spnEndDay.Value = int.Parse(values[0]);
            _spnEndMonth.Value = int.Parse(values[1]);
            _spnEndYear.Value = int.Parse(values[2]);
        }
    }

    public SearchDialog(Window parent) : this(parent, new Builder("SearchDialog.glade"))
    {
        SetupSpns();
    }

    private SearchDialog(Window parent, Builder builder) : base(builder.GetRawObject("SearchDialog"))
    {
        var dialog = (Dialog)builder.GetObject("SearchDialog");
        dialog.TransientFor = parent;
        dialog.Modal = true;
        builder.Autoconnect(this);
    }

    private void OnChkSearchByDateClicked(object sender, EventArgs e)
    {
        SetSpnSensitive(_chkSearchByDate.Active);
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
        Respond(ResponseType.Ok);
    }

    private void OnCancelButtonClicked(object sender, EventArgs e)
    {
        Respond(ResponseType.Cancel);
    }

    private void SetupSpns()
    {
        _spnStartDay.SetRange(1, 31);
        _spnStartDay.SetIncrements(1, 1);
        _spnStartDay.Value = 1;

        _spnStartMonth.SetRange(1, 12);
        _spnStartMonth.SetIncrements(1, 1);
        _spnStartMonth.Value = 1;

        _spnStartYear.SetRange(1970, 2025);
        _spnStartYear.SetIncrements(1, 1);
        _spnStartYear.Value = 2025;

        _spnEndDay.SetRange(1, 31);
        _spnEndDay.SetIncrements(1, 1);
        _spnEndDay.Value = 1;

        _spnEndMonth.SetRange(1, 12);
        _spnEndMonth.SetIncrements(1, 1);
        _spnEndMonth.Value = 1;

        _spnEndYear.SetRange(1970, 2025);
        _spnEndYear.SetIncrements(1, 1);
        _spnEndYear.Value = 2025;
    }

    private void SetSpnSensitive(bool value)
    {
        _spnStartDay.Sensitive = value;
        _spnStartMonth.Sensitive = value;
        _spnStartYear.Sensitive = value;
        _spnEndDay.Sensitive = value;
        _spnEndMonth.Sensitive = value;
        _spnEndYear.Sensitive = value;
    }
}