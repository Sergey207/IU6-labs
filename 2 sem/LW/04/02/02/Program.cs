namespace _02;

public static class Program
{
    private static int _n;

    private static int Main()
    {
        Console.Write("Введите число строк: ");
        if (!int.TryParse(Console.ReadLine(), out _n))
        {
            Console.WriteLine("Введено неверное число строк!");
            return 1;
        }

        if (_n <= 0)
        {
            Console.WriteLine("Число строк должно быть больше 0!");
            return 1;
        }

        var strings = new string[_n];
        if (InputStrings(strings) != 0)
            return 1;

        var result = new string[_n];
        var nResult = 0;
        for (var i = 0; i < _n; i++)
        {
            if ((i + 1) % 2 == 0)
            {
                if (strings[i][0] == 'c')
                {
                    result[nResult++] = strings[i];
                    if (ChangeString(ref result[nResult - 1]) != 0) return 1;
                }
                else if (strings[i][0] != 'e')
                    result[nResult++] = strings[i];
            }
            else
            {
                result[nResult++] = strings[i];
            }
        }

        Console.WriteLine("Исходная последовательность:");
        foreach (var s in strings)
            Console.Write(s + " ");
        Console.WriteLine("\nИзменённая последовательность:");
        for (int i = 0; i < nResult; i++)
            Console.Write(result[i] + " ");

        return 0;
    }

    private static int InputStrings(string[] strings)
    {
        Console.WriteLine("Введите строки:");
        for (var i = 0; i < _n; i++)
        {
            var input = Console.ReadLine();
            if (input == null)
            {
                Console.WriteLine("Ошибка при вводе строки!");
                return 1;
            }

            strings[i] = input;
        }

        return 0;
    }

    private static int ChangeString(ref string s)
    {
        Console.Write($"Введите строку, замещающую {s}: ");
        var input = Console.ReadLine();
        if (input == null)
        {
            Console.WriteLine("Ошибка при вводе строки!");
            return 1;
        }

        s = input;
        return 0;
    }
}