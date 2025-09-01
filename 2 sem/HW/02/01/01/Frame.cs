namespace _01;

public class Frame : Rect
{
    private int _border;
    public Frame(int width, int height, int border) : base(width, height)
    {
        SetBorder(border);
    }
    public int GetBorder()
    {
        return _border;
    }
    public void SetBorder(int border)
    {
        _border = int.Max(0, border);
    }
    public int GetMaxPhotoArea()
    {
        return (GetWidth() + _border) * (GetHeight() + _border);
    }
    public int GetMaxWidth()
    {
        return GetWidth() + _border;
    }
    public int GetMaxHeight()
    {
        return GetHeight() + _border;
    }
    public new void PrintInfo()
    {
        base.PrintInfo();
        Console.WriteLine($"Max photo area: {GetMaxPhotoArea()}");
    }
}


