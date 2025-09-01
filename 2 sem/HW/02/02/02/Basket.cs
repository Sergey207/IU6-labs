using System.Collections;

namespace _02;

public class Basket
{
    private ArrayList _mushrooms = new();
    public Basket(Mushroom[] mushrooms)
    {
        _mushrooms.AddRange(mushrooms);
    }
    public void AddMushroom(Mushroom mushroom)
    {
        _mushrooms.Add(mushroom);
    }
    public void RemoveMushroom(int index)
    {
        if (index >= 0 && index < _mushrooms.Count)
            _mushrooms.RemoveAt(index);
    }
    public void PrintInfo()
    {
        foreach (Mushroom mushroom in _mushrooms)
        {
            mushroom.PrintInfo();
        }
    }
    public int UsefulWeight()
    {
        var result = 0;
        foreach (Mushroom mushroom in _mushrooms)
        {
            if (mushroom.GetMushroomType() != MushroomType.Inedible)
                result += mushroom.GetWeight();
        }
        return result;
    }
}