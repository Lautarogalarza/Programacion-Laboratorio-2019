#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleados.h"

void initMenu(eMenu menues[], int tam)
{
    int codigo[10] = {234, 453, 112, 876, 543, 857, 322, 207, 765, 923};
    char descripciones[10][51]={"Juana","Jose","Alberto","Sonia","Ana","Pedro","Sol","Juan","Felipe","Beatriz"};
    float importes[10] = { 235.50, 340, 457, 234, 132, 287, 321, 216, 298.50, 558};


    for(int i; i<tam; i++)
    {
        menues[i].codigoMenu=codigo[i];

        strcpy(menues[i].descripcion , descripciones[i]);

        menues[i].Importe=importes[i];



    }
}
