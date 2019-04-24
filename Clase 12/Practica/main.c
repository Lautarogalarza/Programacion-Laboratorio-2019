#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMSECTOR 5
#define TAMMENU 10
#include "Empleados.h"



int main()
{

  eMenu menu[10];

 initMenu(menu, TAMMENU);

 printf("\n\n");

 for(int i=0;i<TAMMENU;i++)
 {
     printf("%d %s &f" , menu[i].codigoMenu , menu[i].descripcion , menu[i].Importe);
 }



return 0;
}
