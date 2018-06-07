using System;

namespace misc
{
    class Program
    {
        static void Main(string[] args)
        {
            bool a = false, b = true;

            Pair<bool, bool> bo = new Pair<bool, bool>(a, b);

            Console.WriteLine("First: {0} Second: {1}", bo.getKey(), bo.getValue());

            Pair<bool, bool> boRev = bo.reverse();

            Console.WriteLine("First: {0} Second: {1}", boRev.getKey(), boRev.getValue());

            Console.Read();
        }
    }
}
