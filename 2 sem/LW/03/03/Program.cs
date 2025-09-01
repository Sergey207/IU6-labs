namespace _03;

public class Program
{
    private static double a, b, c;

    private static void Main()
    {
        Console.WriteLine("Эта программа решает уравнение Ax^2 + Bx + C = 0");
        Console.WriteLine("Введите аргументы A, B, C: ");
        if (!double.TryParse(Console.ReadLine(), out a) || !double.TryParse(Console.ReadLine(), out b) ||
            !double.TryParse(Console.ReadLine(), out c))
        {
            Console.WriteLine("Ошибка в введённых данных!");
            return;
        }

        Console.WriteLine("{0}x^2 + {1}x + {2} = 0", a, b, c);

        if (a == 0)
        {
            if (b == 0)
            {
                if (c == 0)
                {
                    Console.WriteLine("x - любое действительное число!");
                }
                else
                {
                    Console.WriteLine("Корней среди действительных чисел нет!");
                }
            }
            else
            {
                Console.WriteLine("x = {0}", -c / b);
            }
        }
        else
        {
            var D = b * b - 4 * a * c;
            if (D == 0)
                Console.WriteLine("x = {0}", -b / (2 * a));
            else if (D < 0)
                Console.WriteLine("Корней среди действительных чисел нет!");
            else
            {
                Console.WriteLine("x1 = {0}", (-b - double.Sqrt(D)) / (2 * a));
                Console.WriteLine("x2 = {0}", (-b + double.Sqrt(D)) / (2 * a));
            }
        }
    }
}