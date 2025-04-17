#include <stdio.h>
#include <stdlib.h>

int main()
{
    long binary1, binary2;
    int i = 0, kalan = 0, sum[20];

    printf("Enter the first binary number: ");
    scanf("%ld", &binary1);
    printf("Enter the second binary number: ");
    scanf("%ld", &binary2);
    while (binary1 != 0 || binary2 != 0)
    {
        sum[i++] =(binary1 % 10 + binary2 % 10 + kalan) % 2;
        kalan =(binary1 % 10 + binary2 % 10 + kalan) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
    if (kalan != 0)
        sum[i++] = kalan;
    --i;
    printf("Sum of two binary numbers: ");
    while (i >= 0)
        printf("%d", sum[i--]);
    return 0;
}/*

int main()
{
    int i,sayi1[7],sayi2[7];
    float bolum,bolum2;
    printf("Binary seklindeki ilk sayiyi giriniz.(6 basamaklý sayilar giriniz.)");
    for(i=0;i<6;i++)
    scanf("%d",&sayi1[i]);
    printf("Binary seklindeki ikinci sayiyi giriniz.(6 basamaklý sayilar giriniz.)");
    for(i=0;i<6;i++)
    scanf("%d",&sayi2[i]);
    int sonuc1,sonuc2;
    for(i=6; i>0 ; i--)
    {
        bolum=sayi1[i];
        sonuc1+=bolum*pow(2,i);
        bolum=sayi2[i];
        sonuc2+=bolum*pow(2,i);
    }
    for(i=6; i>0 ; i--)
    {
        bolum=sayi1/pow(10,i);
        sayi1+=bolum*pow(2,i);
    }
    printf("sonuc: %d ",sonuc1+sonuc2);

}
*/
/*
int main()
{
    int dizi[10];
    int i,j;
    int a=9,b=0;
    int sayac=0;

    for(int i=0;i<5;i++)
    {
            if(b%2==0)
            {
                printf("%d.eleman",b);scanf("%d",&dizi[b]);
            }
            if(a%2==1)
            {
                printf("%d.eleman",a);scanf("%d",&dizi[a]);
            }
    }

    for(j=0;j<10;j++)
        printf("%d",dizi[j]);

}
*/
