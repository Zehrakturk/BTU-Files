#include <stdio.h>
#include <stdlib.h>

int main(int n, char *dizi[])
{
    printf("Gelen arguman syisi: %d",n);
    float a,b,sonuc;

    a=atof(dizi[1]);
    b=atof(dizi[3]);

    char islem=dizi[2][0];

    switch(islem)
    {
    case '+':
        sonuc=a+b;
        break;
    case '-':
        sonuc= a-b;
        break;
    case 'x':
        sonuc=a*b;
        break;
    case'/':
        sonuc=a/b;
        break;
    default:
        printf("Taninmayan islem");
    }

    printf("\n\nSonuc: %f",sonuc);
}
