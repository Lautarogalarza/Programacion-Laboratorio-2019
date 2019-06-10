#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int vec[CANT]= {7,5,6,2,8};
    int aux;
    int i;
    int j;


    for(i=0; i<CANT-1; i++)
    {

        for(j=i+1; j<CANT; j++)
        {
            if(vec[i]>vec[j])
            {

                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;

            }
        }
    }

    for(i=0; i<CANT; i++)
    {
        printf("%d", vec[i]);
    }
    return 0;
}
