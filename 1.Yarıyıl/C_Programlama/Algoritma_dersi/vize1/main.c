#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x=1;
    float toplam;
    do
    {
        toplam+=pow(x/2,2*x);
        x++;

    }while(x<=10);
    printf("Toplam %.2f",toplam);
    return 0;
}
