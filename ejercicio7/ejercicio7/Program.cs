using System;
using System.Threading.Tasks;
using System.Diagnostics;

class Program
{
    static double CalculoPi(int procesador, int limite, int procesadores)
    {
        double cpi = 0;
        for (int i = procesador; i < limite; i += procesadores)
        {
            if (i != 0)
            {
                cpi += 1.0 / (Math.Pow(i, 4)); 
            }
        }
        return cpi;
    }

    static void Main()
    {
        int limite = 1000000;
        int numProcesadores = Environment.ProcessorCount;
        double[] resultados = new double[numProcesadores];

        Parallel.For(0, numProcesadores, procesador =>
        {
            resultados[procesador] = CalculoPi(procesador, limite, numProcesadores);
        });

        double suma = 0;
        foreach (var resultado in resultados)
        {
            suma += resultado;
        }

        double piAproximado = Math.Pow(suma * 90, 1.0 / 4);
        Console.WriteLine(piAproximado);
    }
}
