#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "estudios.h"
#include "peliculas.h"
int main()
{
    ePelicula UnaPelicula[5];

    eEstudio UnEstudio[5];

    char seguir='s';
    char confirma;


    do
    {
        switch(menuEstudio())
        {
        case 1:

            cargarEstructura(UnEstudio,5);
             system("pause");

            break;
        case 2:

              mostrarEstructuras(UnEstudio,5);
               system("pause");

            break;
        case 3:

            modificarEstructura(UnEstudio,5);

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:

            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }

            break;
        default:

            printf("\n Opcion invalida\n\n");
            system("pause");
            break;

        }

    }
    while(seguir=='s');

    return 0;
}

/*int mayorId (eEstructura lista int tam)
int i;

int flag =0;

int aux =0;

for(i=0;i<tam; i++)
{
    if(flag==0 || listai.id>aux)
    {
        aux=listai.id;

        flag=1;
    }

    return aux;//le sumo uno cuando lo cargo en el alta
}

void mostrarEstudioConPeliculas(eEstudio listaEstudio,);
{
    int i;
    int j;

    for(i=0;i<tamest; i++)
    {
        if(listaEstudios[i].estado==OCUPADO)
        {
            mostrarEstudio(listaEstudios[i]);

            for(j=0; j<tampeli;j++)
            {
                if (listaEstudios[i].id==listaPeliculas[j].idEstudios)

                    mostrarpelicula(lista(listapeliculas[j]));
            }
        }
    }
}*/
