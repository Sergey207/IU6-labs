// ReSharper disable SwapViaDeconstruction
namespace _01;

public static class Program
{
    private static int _n;

    public static int Main()
    {
        Console.Write("Введите n (размер матрицы, кратно 3): ");
        if (!int.TryParse(Console.ReadLine(), out _n))
        {
            Console.WriteLine("Ошибка при вводе числа!");
            return 1;
        }

        if (_n < 3 || _n % 3 != 0)
        {
            Console.WriteLine("Число должно быть положительным и кратным 3!");
            return 1;
        }

        var matrix = new int[_n][];
        if (InputMatrix(matrix) != 0) return 1;
        
        PrintMiniMatrix(matrix);
        ChangeMiniMatrix(matrix);
        Console.WriteLine("\n");
        PrintMiniMatrix(matrix);

        return 0;
    }

    private static int InputMatrix(int[][] matrix)
    {
        Console.WriteLine($"Введите матрицу {_n}x{_n} целых чисел:");
        for (var i = 0; i < _n; i++)
        {
            var row = Console.ReadLine();
            if (row == null)
            {
                Console.WriteLine("Ошибка при вводе данных!");
                return 1;
            }

            var elemRow = row.Trim().Split(" ");
            if (elemRow.Length != _n)
            {
                Console.WriteLine($"Количество элементов должно быть равно {_n}!");
                return 1;
            }

            var intRow = new int[_n];
            for (var j = 0; j < _n; j++)
            {
                if (!int.TryParse(elemRow[j], out intRow[j]))
                {
                    Console.WriteLine("Ошибка при вводе данных!");
                    return 1;
                }
            }

            matrix[i] = intRow;
        }

        return 0;
    }

    private static void PrintMiniMatrix(int[][] matrix)
    {
        for (int i = 0; i < _n; i++)
        {
            for (int j = 0; j < _n; j++)
            {
                Console.Write(matrix[i][j] + " ");
                if (j == (_n / 3 - 1) || j == (_n / 3 * 2 - 1))
                    Console.Write(" ");
            }

            Console.WriteLine();
            if (i == (_n / 3 - 1) || i == (_n / 3 * 2 - 1))
                Console.WriteLine();
        }
    }

    private static void ChangeMiniMatrix(int[][] matrix)
    {
        // Меняем матрицы на главной диагонали
        for (var i = 0; i < _n / 3; i++)
        {
            for (var j = 0; j < _n / 3; j++)
            {
                var temp = matrix[i][j];
                matrix[i][j] = matrix[i + _n * 2 / 3][j + _n * 2 / 3];
                matrix[i + _n * 2 / 3][j + _n * 2 / 3] = temp;
            }
        }
        // Меняем матрицы на побочной диагонали
        for (var i = _n * 2 / 3; i < _n; i++)
        {
            for (var j = 0; j < _n / 3; j++)
            {
                var temp = matrix[i][j];
                matrix[i][j] = matrix[i - _n * 2 / 3][j + _n * 2 / 3];
                matrix[i - _n * 2 / 3][j + _n * 2 / 3] = temp;
            }
        }
    }
}