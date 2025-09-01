namespace _02;

internal static class Program
{
    private static void Main()
    {
        Console.WriteLine("======Грибы======");
        var mushroom1 = new Mushroom("Белый гриб", 100, MushroomType.Edible);
        var mushroom2 = new Mushroom("Поганка", 60, MushroomType.Inedible);
        mushroom1.PrintInfo();
        mushroom2.PrintInfo();

        Console.WriteLine("======Корзинка======");
        var basket = new Basket([mushroom1, mushroom2]);
        basket.PrintInfo();
        Console.WriteLine($"Полезный вес: {basket.UsefulWeight()}");
        Console.WriteLine("Удаление белого гриба...");
        basket.RemoveMushroom(0);
        basket.PrintInfo();
        Console.WriteLine($"Полезный вес: {basket.UsefulWeight()}");
        var newMushroom = new Mushroom("Подберёзовик", 30, MushroomType.Edible);
        Console.WriteLine($"Новый гриб: {newMushroom.GetName()}");
        basket.AddMushroom(newMushroom);
        basket.PrintInfo();
        Console.WriteLine($"Полезный вес: {basket.UsefulWeight()}");
    }
}