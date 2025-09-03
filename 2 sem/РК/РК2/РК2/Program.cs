namespace _02;

static class Program
{
    public static void Main()
    {
        var s = new S();
        var q = new Q();
        Test(s);
        Test(q);
    }

    private static void Test(R r)
    {
        r.met();
    }
}