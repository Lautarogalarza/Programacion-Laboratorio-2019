#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Numero;
    char Respuesta;
    int SumaNegativos=0;
    int SumaPositivos=0;
    int ContadorPositivos=0;
    int ContadorNegativos=0;
    int ContadorCeros=0;
    int ContadorPares=0;
    float promedioPositivos;
    float promedioNegativos;
    int Maximo;
    int Minimo;
    int Diferencia;
    int Bandera=0;

    do
    {
        printf("ingrese un numero: ");
        scanf("%d", &Numero);

        printf("Desea empezar?: <s-n> \n");
        fflush(stdin);
        scanf("%c", &Respuesta);

        if(Numero<0)
        {
            SumaNegativos=SumaNegativos+Numero;
            //SumaNegativos+=Numero;
            ContadorNegativos++;
        }

        else
        {
            if(Numero>0)
            {
                SumaPositivos=SumaPositivos+Numero;
                //SumaPositivos+=Numero;
                ContadorPositivos++;
            }
            else
            {
                ContadorCeros++;
            }
        }


        if(Numero%2==0)
        {
            ContadorPares++;
        }

        if(Bandera==0 || Numero>Maximo)
        {
            Maximo=Numero;


        }

        if(Bandera==0 || Numero<Minimo)
        {
            Minimo=Numero;

            Bandera=1;
        }


    }
    while(Respuesta=='s');

    promedioPositivos=(float)SumaPositivos/ContadorPositivos;
    promedioNegativos=(float)SumaNegativos/ContadorNegativos;
    Diferencia=SumaPositivos-SumaNegativos;

    printf("la suma de negativos es: %d \n", SumaNegativos);
    printf("la suma de positivos es: %d \n", SumaPositivos);
    printf("la cantidad de positivos es: %d \n", ContadorPositivos);
    printf("la cantidad de negativos es: %d \n", ContadorNegativos);
    printf("la cantidad de pares es: %d \n", ContadorPares);
    printf("la cantidad de ceros es: %d \n", ContadorCeros);
    printf("el promedio de los positivos es: %.2f \n", promedioPositivos);
    printf("el promedio de los negativos es: %.2f \n", promedioNegativos);
    printf("la diferencia entre los positivos y negativos es: %d \n", Diferencia);



    return 0;




}
