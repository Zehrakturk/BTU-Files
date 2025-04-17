#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char sayi_m[18];int n;
    double sayi=0.0;
    int i,j,basamak;
    printf("Ondalik sayiyi giriniz.");
    gets(sayi_m);
    for(i=0;i<strlen(sayi_m)-1;i++)//terminating karakteden dolayi strlen-1 yaptik
    {
        if(sayi_m[i]=='.')
        {
            n=i;
            break;
        }
    }
    for(j=n-1;j>=0;j--)
    {
        sayi+=(sayi_m[j]-48)*pow(10,n-1-j);
    }

    for(j=n+1; sayi_m{j}!='\0'; j++) //j<=strlen(sayi_m)-n kullanabilir miydik??
    {
        sayi+=(sayi_m[j]-48)*pow(10,n-j);
    }
    printf("Metnin sayiya cevrilmis hali:%10.6lf\n",sayi);

    return 0;
}
