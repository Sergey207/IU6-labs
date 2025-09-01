namespace _02;

public class Mushroom
{
    private string _name;
    private int _weight;
    private MushroomType _type;
    public Mushroom(string name, int weight, MushroomType type)
    {
        _name = name;
        _weight = int.Max(0, weight);
        _type = type;
    }
    public string GetName()
    {
        return _name;
    }
    public int GetWeight()
    {
        return _weight;
    }
    public MushroomType GetMushroomType()
    {
        return _type;
    }
    public void PrintInfo()
    {
        Console.WriteLine($"Гриб {_name}, вес: {_weight}");
        switch (_type)
        {
            case MushroomType.Edible:
                Console.WriteLine("Съедобный");
                break;
            case MushroomType.Inedible:
                Console.WriteLine("Несъедобный");
                break;
            case MushroomType.ConditionallyEdible:
                Console.WriteLine("Условно съедобный");
                break;
        }
    }
}
