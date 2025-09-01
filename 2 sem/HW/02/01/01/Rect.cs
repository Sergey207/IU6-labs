namespace _01;

public class Rect
{
    private int _width;
    private int _height;

    public Rect(int width, int height)
    {
        SetWidth(width);
        SetHeight(height);
    }

    public int GetWidth()
    {
        return _width;
    }

    public int GetHeight()
    {
        return _height;
    }

    public void SetWidth(int width)
    {
        _width = int.Max(0, width);
    }

    public void SetHeight(int height)
    {
        _height = int.Max(0, height);
    }

    public int GetArea()
    {
        return _width * _height;
    }

    public void PrintInfo()
    {
        Console.WriteLine($"Rect {_width}x{_height}, area={GetArea()}");
    }
}