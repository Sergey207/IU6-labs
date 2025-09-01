namespace _01;

internal static class Program
{
    private static void TestRect()
    {
        Console.WriteLine("=====Checking rectangle=====");
        var rect = new Rect(640, 480);
        rect.PrintInfo();
        Console.WriteLine($"Area: {rect.GetWidth() * rect.GetHeight()}");
        Console.WriteLine($"Area: {rect.GetArea()}");
        Console.WriteLine("width * 4 && height * 2");
        rect.SetWidth(rect.GetWidth() * 4);
        rect.SetHeight(rect.GetHeight() * 2);
        rect.PrintInfo();
        Console.WriteLine($"New area: {rect.GetArea()}");
    }

    private static void TestFrame()
    {
        Console.WriteLine("=====Checking frame=====");
        var frame = new Frame(20, 5, 2);
        frame.PrintInfo();
        Console.WriteLine($"Area: {frame.GetArea()}");
        Console.WriteLine($"Max photo size: {frame.GetMaxWidth()}x{frame.GetMaxHeight()}");
        Console.WriteLine($"Max photo area: {frame.GetMaxPhotoArea()}");
        Console.WriteLine("width * 2 && height * 2");
        frame.SetWidth(frame.GetWidth() * 2);
        frame.SetHeight(frame.GetHeight() * 2);
        frame.PrintInfo();
        Console.WriteLine("border / 2");
        frame.SetBorder(frame.GetBorder() / 2);
        frame.PrintInfo();
    }

    public static void Main()
    {
        TestRect();
        TestFrame();
    }
}

