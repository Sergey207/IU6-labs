using System;
using Gtk;
using UI = Gtk.Builder.ObjectAttribute;

namespace _03;

class MainWindow : Window
{
    [UI] private readonly Label _label = null;

    [UI] private readonly Button _button1 = null;
    [UI] private readonly Button _button2 = null;
    [UI] private readonly Button _button3 = null;
    [UI] private readonly Button _button4 = null;
    [UI] private readonly Button _button5 = null;
    [UI] private readonly Button _button6 = null;
    [UI] private readonly Button _button7 = null;
    [UI] private readonly Button _button8 = null;
    [UI] private readonly Button _button9 = null;

    private string _curSign;
    private int _moveNum;
    private bool _gameEnded;

    public MainWindow() : this(new Builder("MainWindow.glade"))
    {
        _curSign = "X";
        _moveNum = 1;
        _gameEnded = false;
    }

    private MainWindow(Builder builder) : base(builder.GetRawOwnedObject("MainWindow"))
    {
        builder.Autoconnect(this);

        DeleteEvent += Window_DeleteEvent;
    }

    private void Window_DeleteEvent(object sender, DeleteEventArgs a)
    {
        Application.Quit();
    }

    private void ClickTicTacToeButton(object sender, EventArgs a)
    {
        Button button = (Button)sender;
        if (string.IsNullOrEmpty(button.Label) & !_gameEnded)
        {
            button.Label = _curSign;
            if (!string.IsNullOrEmpty(_button1.Label)
                & _button1.Label == _button2.Label
                & _button2.Label == _button3.Label
                |
                !string.IsNullOrEmpty(_button4.Label)
                & _button4.Label == _button5.Label
                & _button5.Label == _button6.Label
                |
                !string.IsNullOrEmpty(_button7.Label)
                & _button7.Label == _button8.Label
                & _button8.Label == _button9.Label
                |
                !string.IsNullOrEmpty(_button1.Label)
                & _button1.Label == _button4.Label
                & _button4.Label == _button7.Label
                |
                !string.IsNullOrEmpty(_button2.Label)
                & _button2.Label == _button5.Label
                & _button5.Label == _button8.Label
                |
                !string.IsNullOrEmpty(_button3.Label)
                & _button3.Label == _button6.Label
                & _button6.Label == _button9.Label
                |
                !string.IsNullOrEmpty(_button1.Label)
                & _button1.Label == _button5.Label
                & _button5.Label == _button9.Label
                |
                !string.IsNullOrEmpty(_button3.Label)
                & _button3.Label == _button5.Label
                & _button5.Label == _button7.Label
               )
            {
                _gameEnded = true;
                _label.Text = "Ход " + _moveNum + ": Победил " + _curSign + "!";
            }
            else if (!string.IsNullOrEmpty(_button1.Label) &
                     !string.IsNullOrEmpty(_button2.Label) &
                     !string.IsNullOrEmpty(_button3.Label) &
                     !string.IsNullOrEmpty(_button4.Label) &
                     !string.IsNullOrEmpty(_button5.Label) &
                     !string.IsNullOrEmpty(_button6.Label) &
                     !string.IsNullOrEmpty(_button7.Label) &
                     !string.IsNullOrEmpty(_button8.Label) &
                     !string.IsNullOrEmpty(_button9.Label)
                    )
            {
                _gameEnded = true;
                _label.Text = "Ход " + _moveNum + ": Ничья!";
            }
            else
                _label.Text = "Ход " + _moveNum + ": " + _curSign + " сходил на " + button.Name + " клетку";

            if (_curSign == "X")
                _curSign = "O";
            else
                _curSign = "X";
            _moveNum += 1;
        }
    }

    private void NewGameButtonClick(object sender, EventArgs a)
    {
        _curSign = "X";
        _moveNum = 1;
        _gameEnded = false;
        _button1.Label = "";
        _button2.Label = "";
        _button3.Label = "";
        _button4.Label = "";
        _button5.Label = "";
        _button6.Label = "";
        _button7.Label = "";
        _button8.Label = "";
        _button9.Label = "";
        _label.Text = "Игра началась!";
    }
}