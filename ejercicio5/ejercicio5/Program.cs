using System;
using System.Threading;

class Serie
{
    static void Main()
    {
        int n = 10000;
        int a = 2;
        int b = 2;
        int[] resultados = new int[n];
        object lockObject = new object();

        Thread[] hilos = new Thread[n];

        for (int i = 0; i < n; i++)
        {
            int indice = i; 
            hilos[i] = new Thread(() =>
            {
                int resultado;
                if (indice % 2 == 1 && indice > 1)
                {
                    resultado = a;
                    a = a + indice;
                }
                else if (indice > 2)
                {
                    resultado = b;
                    b = indice;
                }
                else
                {
                    resultado = 0;
                }

                lock (lockObject)
                {
                    resultados[indice] = resultado;
                }
            });

            hilos[i].Start();
        }

        foreach (var hilo in hilos)
        {
            hilo.Join();
        }

        for (int i = 3; i < 10000; i++) 
        {
            Console.Write(resultados[i] + ",");
        }
    }
}