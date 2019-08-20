using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_01
{
    class Program
    {
        static void Main(string[] args)
        {
            //string nombre = "Lautaro";
            //string apellido = "Galarza";

            string nombre;
            string apellido;

            Console.Title = "Ejercicio de bienvenida";

            
            Console.WriteLine("Hola mundo C#");

            Console.Write("Ingresa tu nombre:");
            nombre=Console.ReadLine();
            Console.Write("Ingresa tu apellido:");
            apellido =Console.ReadLine();
            Console.WriteLine("Mi nombre es {0} - {1} ", nombre, apellido);
            Console.ReadLine();
             
        }
    }
}
