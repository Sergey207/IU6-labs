using System;
using Gtk;
using UI = Gtk.Builder.ObjectAttribute;

// ReSharper disable SwapViaDeconstruction

namespace _05
{
    class MainWindow : Window
    {
        [UI] private TextView _inputText;
        [UI] private TextView _outputText;

        public MainWindow() : this(new Builder("MainWindow.glade"))
        {
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

        private void OnChangeClicked(object sender, EventArgs e)
        {
            var text = _inputText.Buffer;
            if (text.LineCount % 3 != 0)
            {
                ShowErrorMessage("Количество строк должно быть кратно 3!");
                return;
            }

            var matrix = new int[text.LineCount][];
            if (InputMatrix(matrix) == 1) return;
            ChangeMiniMatrix(matrix);
            PrintMiniMatrix(matrix);
        }

        private void ShowErrorMessage(string message)
        {
            using var md = new MessageDialog(
                this,
                DialogFlags.Modal,
                MessageType.Error,
                ButtonsType.Ok,
                message);
            md.Title = "Ошибка!";
            md.Run();
        }

        private int InputMatrix(int[][] matrix)
        {
            var text = _inputText.Buffer;
            var i = 0;
            foreach (var row in text.Text.Split("\n"))
            {
                var elemRow = row.Trim().Split(" ");
                if (elemRow.Length != text.LineCount)
                {
                    ShowErrorMessage($"Количество элементов должно быть равно {text.LineCount}!");
                    return 1;
                }

                var intRow = new int[text.LineCount];
                for (var j = 0; j < text.LineCount; j++)
                {
                    if (!int.TryParse(elemRow[j], out intRow[j]))
                    {
                        ShowErrorMessage("Ошибка при вводе данных!");
                        return 1;
                    }
                }

                matrix[i++] = intRow;
            }

            return 0;
        }

        private void ChangeMiniMatrix(int[][] matrix)
        {
            var n = _inputText.Buffer.LineCount;
            // Меняем матрицы на главной диагонали
            for (var i = 0; i < n / 3; i++)
            {
                for (var j = 0; j < n / 3; j++)
                {
                    var temp = matrix[i][j];
                    matrix[i][j] = matrix[i + n * 2 / 3][j + n * 2 / 3];
                    matrix[i + n * 2 / 3][j + n * 2 / 3] = temp;
                }
            }

            // Меняем матрицы на побочной диагонали
            for (var i = n * 2 / 3; i < n; i++)
            {
                for (var j = 0; j < n / 3; j++)
                {
                    var temp = matrix[i][j];
                    matrix[i][j] = matrix[i - n * 2 / 3][j + n * 2 / 3];
                    matrix[i - n * 2 / 3][j + n * 2 / 3] = temp;
                }
            }
        }

        private void PrintMiniMatrix(int[][] matrix)
        {
            _outputText.Buffer.Clear();
            var n = _inputText.Buffer.LineCount;
            for (var i = 0; i < n; i++)
            {
                for (var j = 0; j < n; j++)
                {
                    _outputText.Buffer.Text += matrix[i][j] + " ";
                    if (j == (n / 3 - 1) || j == (n / 3 * 2 - 1))
                        _outputText.Buffer.Text += " ";
                }

                _outputText.Buffer.Text += "\n";
                if (i == (n / 3 - 1) || i == (n / 3 * 2 - 1))
                    _outputText.Buffer.Text += "\n";
            }
        }
    }
}