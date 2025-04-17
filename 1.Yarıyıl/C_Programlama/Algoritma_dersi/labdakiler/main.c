#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

/*
int main()
{
    float vize ,Final,quiz1,quiz2,ort,proje1,proje2;
    printf("Vize notunuzu giriniz:");
    scanf("%f",&vize);
    printf("Final notunuzu giriniz:");
    scanf("%f",&Final);
    printf("quiz1 notunuzu giriniz:");
    scanf("%f",&quiz1);
    printf("quiz2 notunuzu giriniz:");
    scanf("%f",&quiz2);
    printf("proje1 notunuzu giriniz:");
    scanf("%f",&proje1);
    printf("proje2 notunuzu giriniz:");
    scanf("%f",&proje2);
    ort=(vize*30)/100+Final*4/10+quiz1*1/20 + quiz2*2/20 + proje1*1/10+ proje2*2/10;
    if(ort<60)
    {
        printf("Dersten kaldiniz.\n");
        printf("Ortalamaniz:%f\n",ort);
    }
    else
    {
        printf("Dersten kaldiniz.\n");
        printf("Ortalamaniz:%f\n",ort);
    }
}
int main()
{
    int gun,yenigun;
    int artan;
    printf("Bugun hangi gun ?");scanf("%d",&gun);
    switch(gun)
    {
        case 1:printf("bugun pazartesi\n");
        case 2:printf("Bugun sali\n");break;
        case 3:printf("bugun carsamba\n");break;
        case 4:printf("bugun persembe\n");break;
        case 5 :printf("Bugun cuma\n");break;
        case 6 :printf("bugun cumartesi\n");break;
        case 7 :printf("Bugun pazar\n");break;
        default :printf("yanlis secim girdiniz\n");break;

    }
     printf("Kac gun sonrasi");scanf("%d",&artan);
     yenigun=(gun+artan)%7;
    switch(yenigun)
    {
        case 1:{printf("bugun %s",gun);
        printf("%d gun sonra pazartesi",artan);break;}
        case 2:{printf("%d gun sonra sali\n",artan);}break;
        case 3:{printf("%d gun sonra carsamba\n",artan);break;}
        case 4:{printf("%d gun sonra persembe\n ",artan);break;}
        case 5 :{printf("%dgun sonra cuma\n",artan);break;}
        case 6 :{printf("%dgun sonra cumartesi\n",artan);break;}
        case 7 :{printf("%dgun sonra pazar\n",artan);break;}

    }
}
int main()
{
    char secim;
    float mil,km;
    printf("hangi birimde deger girilecek(mil icin m km icin k giriniz)\n");scanf("%c",&secim);
    switch(secim)
    {
        case 'm':
        {
            printf("kac mil?");scanf("%f",&mil);
            km=mil*0.000914;
            printf("%f
            mil: %f km",mil,km);
        }break;
        case 'M':
        {
             printf("kac mil?");scanf("%f",&mil);
            km=mil*0.000914;
            printf("%fmil: %f km",mil,km);
        }break;
        case 'k':
            {
            printf("kac km?");scanf("%f",&km);
            mil=km*1.609344;
            printf("%fmil: %d km",km,mil);
            }break;
         case 'K':
            {
            printf("kac km?");scanf("%f",&km);
            mil=km*1.609344;
            printf("%fmil: %f km",km,mil);
            }break;
    }

}*//*
int main()
{
    int secim,sayi1,sayi2;
    printf("1-toplama\n2-cikarma\n3-carpma\n4-bolme");scanf("%d",&secim);
    printf("sayi1:");scanf("%d,&sayi1);
    printf("sayi2:");scanf("%d,&sayi2);


    switch(secim)
    {
        case 1:{printf("%d+%d:%d",sayi1,sayi2,sayi1+sayi2);}
        break;
        case 2:{printf("%d-%d:%d",sayi1,sayi2,sayi1-sayi2);}
        break;
        case 3:{printf("%d*%d:%d",sayi1,sayi2,sayi1*sayi2);}
        break;
        case 4:{printf("%d/%d:%d",sayi1,sayi2,sayi1/sayi2);}
        break;
        default:printf("yanlis secim yaptiniz.");
    }

}*/
/*
int main()
{
    int ay;
    printf("yilin kacinci ayi?\n");scanf("%d",&ay);

    switch(ay)
    {
        case 1:printf("kis ayindasiniz");
        break;
        case 2:printf("kis ayindasiniz");
        break;
        case 3:printf("ilkbahar ayindasiniz");
        break;
        case 4:printf("ilkbahar ayindasiniz");
        break;
        case 5:printf("ilkbahar ayindasiniz");
        break;
        case 6:printf("yaz ayindasiniz");
        break;
        case 7:printf("yaz ayindasiniz");
        break;
        case 8:printf("yaz ayindasiniz");
        break;
        case 9:printf("sonbahar ayindasiniz");
        break;
        case 10:printf("sonbahar ayindasiniz");
        break;
        case 11:printf("sonbahar ayindasiniz");
        break;
        case 12:printf("kis ayindasiniz");
        default:printf("Gecersiz bir deger girdiniz.");
        break;
    }
}

int main()
{
    int a,i;
    printf("Bir sayi giriniz.");
    scanf("%d",&a);
    for(i=0;i<=a;)
    {
        printf("%d\n",i);
        i+=3;
    }
}
*/
/*
int main()
{
    int a,sayac;
    for(int i=1;i<=20;i++)
    {
        if(i%3==0)
            continue;
        else
        {
            printf("%d\t",i);
            sayac++;
            if(sayac==5)
            {
                printf("\n");
                sayac=0;
            }
        }
    }
}*//*
int main()
{
    int i,j;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10-i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf(" ");
        }
        for(j=((10-i)*2)-1;j>=1;j--)
        {
            printf("*");
        }
        printf("\n");
    }
}
*//*
int main()
{
    int sifre,sifre2;
    int boyut,sayac=0,i;
    printf("Bir sifre belirleyiniz.");
    scanf("%d",&sifre);
    printf("\n\nSifre olusturma islemi basarili!!\n\n");

    printf("\nGiris yapmak icin sifre giriniz.\n");
    do
    {
        scanf("%d",&sifre2);
        if(sifre==sifre2)
        {
        printf("Dogru sifre girdiniz.");
         break;
        }
        else
        {
            printf("\nYanlis giris yaptiniz!!\nTekrar deneyin!!\n\n");
        }

    }while(sifre!=sifre2);

}*///BU DERS ILE ALAKALI DEGIL;
/*
int main()
{
    int i,j,k,m;
    for(i=1;i<=4;i++)
    {
        for(k=1;k<=i;k++)
        printf("%d",k);
        for(j=6;j>(2*i-2);j--)
        {
            printf(" ");
        }
        for(m=0;m<i;m++)
        {
            printf("%d",i-m);
        }
        if(i>=2)
        {
            for(m=i;m>1;m--)
            {
                printf("%d",i-m+2);
            }
        }
        for(j=6;j>(2*i-2);j--)
        {
            printf(" ");
        }
        for(k=i;k>0;k--)
        printf("%d",k);

        printf("\n");
    }
}*//*
int main()
{
    int n,k,a=1;
    int i,j;
    printf("n i giriniz.");scanf("%d",&n);k=n-3;
    for(i=1;i<n+1;i++)
    {
        printf("%d",n-(n-i));
        for(j=2*n-3+a;j>0;j--)
        {
            printf("*");
        }a-=2;
        printf("%d",n-(n-i));
        printf("\n");
        for(j=1;j<3;j++)
        {
            printf("%d",n-(n-j));
        }
        for(j=2*n-3+a;j>0;j--)
        {
            printf("*");
        }a-=2;
        for(j=1;j<n-1;j++)
        {
            printf("%d",n-(n-j));
        }
        printf("\n");
        for(j=1;j<n;j++)
        {
            printf("%d",n-(n-j));
        }
        for(j=2*n-3+a;j>0;j--)
        {
            printf("*");
        }a-=2;
        for(j=n-1;j>0;j--)
        {
            printf("%d",n-(n-j));
        }
        printf("\n");
         for(j=1;j<n+1;j++)
        {
            printf("%d",n-(n-j));
        }
        for(j=2*n-3+a;j>0;j--)
        {
            printf("*");
        }a-=2;
        for(j=n;j>0;j--)
        {
            printf("%d",n-(n-j));

        }

    }
}*//*
int main()
{

    int kisa=5,uzun=8,yukseklik=6;
    for(int i=1; i<=kisa; i++)
    {
        for(int m=1; m<i; m++)
        {
            printf(" ");
        }

        for(int j=1; j<=uzun; j++)
        {
            if(i==1 || i==kisa || j==1 || j==uzun)
                printf("* ");
            else
                printf("  ");
        }

        printf("\n");
    }
    printf("\n-------------------------------------\n");
    char z,satir;
    while(z!='x')
    {
        printf("\n a Alan,c cevre,x cik: \n");
        scanf("%s",&z);
        if(z=='a')
        {
        int alan =kisa*yukseklik;
        printf("\nAlan : %d\n",alan);
        }
        else if(z =='c')
        {

            int cevre=2*(kisa+uzun);
            printf("\nCevre: %d\n",cevre);

        }
        else if(z=='x')
            printf("\n--ciktim--");
        else
        {
                    printf("\n yanlis deger \n");
                }
            }
}*//*
int main()
{
    int kisa=5,uzun=8,yukseklik=6;
    for(int i=1; i<=kisa; i++)
    {
        for(int m=1; m<i; m++)
        {
            printf(" ");
        }

        for(int j=1; j<=uzun; j++)
        {
            if(i==1 || i==kisa || j==1 || j==uzun)
                printf("* ");
            else
                printf("  ");
        }

        printf("\n");
    }
    printf("\n-------------------------------------\n");
    char z;
    do
    {
            printf("\n a Alan,c cevre,x cik: \n");
            scanf("%s",&z);
        if(z=='a')
        {
            int alan =kisa*yukseklik;
            printf("\nAlan : %d\n",alan);
        }
        else if(z =='c')
        {

            int cevre=2*(kisa+uzun);
            printf("\nCevre: %d\n",cevre);

        }

        else
            printf("Yanlis deger girdiniz!!");

    }
    while(z!='x');

    return 0;


}*//*
int main()
{
   int N,i,sayactek=0,sayaccift=0;
   printf("Dizinin boyutunu belirleyiniz.");scanf("%d",&N);
   int dizi[N],ciftler[N/2],tekler[N/2];
   for(i=0;i<N;i++)
   {
       dizi[i]=i+1;
   }


    printf("Dizi:");
    for(i=0;i<N;i++)
    {
        printf("%4d",dizi[i]);
    }
    printf("\n");
    for(i=1;i<N;i++)
    {
        if(dizi[i]%2==1)
        {
            tekler[sayactek++]=i-1;
        }
        else
        {
            ciftler[sayaccift++]=i-1;        }
    }
    printf("Tek sayilar: ");
    for(i=0;i<sayactek;i++)
        printf("%4d",tekler[i]);
    printf("\n");

    printf("\nCiftler:");
    for(i=0;i<N/2;i++)
    {
        printf("%4d",ciftler[i]);
    }





}*/
/*
int main()
{
    char t,dizi[]={"BURSA TEKNIK UNIVERSITESI"};
    int i,j,a=0;

    while(1){

        t=dizi[0];
        for(i=1;i<strlen(dizi);i++)
        {
            dizi[i-1]=dizi[i];a++;
        }
        dizi[i-1]=t;
        printf("%s\r",dizi);
            sleep(1);
    }
}*//*
int topla(int n,...)
{
    int i,toplam;
    va_list arg;
    va_start(arg,n);
    for(i=0;i<n;i++)
    {
        toplam+=va_arg(arg,int);
    }

    return toplam;
}
int main()
{
    printf("topla(2,11,22)=%d\n",topla(2,11,22));
    printf("topla(3,11,22,33)=%d\n",topla(3,11,22,33));
    printf("topla(4,11,22,33,44)=%d\n",topla(2,11,22,33,44));
    printf("topla(5,11,22,33,44,55)=%d\n",topla(2,11,22,33,44,55));


}*/

/*
int maks_bul(int n,...)
{
    va_list listem;
    int i,a;
    va_start(listem,n);
    int maks=va_arg(listem,int);
    for(i=2;i<n;i++)
    {
        if(a=va_arg(listem,int)>maks)
        {
            maks=a;
        }

    }
    return maks;

}
int main()
{
  printf("%d",maks_bul(5,43,67,23,785,5));
}

*/
/*
void argyaz(int n, ...)
{
  va_list ap;
  int i;

  va_start(ap, n);

  for (i = n; i != -1; i = va_arg(ap, int))
    printf("%d ", i);

  va_end(ap);
  putchar('\n');
}

int main(void)
{
   argyaz(5, 2, 14, 84, 97, 15, 24, 48, -1);
   argyaz(84, 51, 1);
   argyaz(-1);
   argyaz(1, -1);

  return 0;
}*//*
int main()
{
   int a=5,b=4;
   int *p,*q;
   p=&a;
   q=&b;
   printf("%d",*p+*q);

}*//*
int main()
{
    int adet,toplam=0, n;
    printf("sayi adedi giriniz.");scanf("%d",&adet);//scanf("%d",&n);
    int dizim[adet];
    int *p=dizim;//int *p=sayim;
    p=(int* )malloc(8);//malloc(adet*4)
    if(p==NULL)
    {
        printf("Program hatasi!!");
    }
    else
    {
        if(adet>2)
        {
            p=(int *)realloc(p,adet*sizeof(int));
        }
    }
    for(int i=0;i<adet;i++)
    {
        scanf("%d",&dizim[i]);//scanf("%d",p+i);
         toplam+=dizim[i];//toplam+=*(p+i);
    }
    printf("toplam :%d",toplam);

    free(p);
}
*//*
void kopyala(char kaynak[],char *hedef,int bas,int son){
    int i;
    hedef=(char*)malloc(sizeof(char)*(son-bas+2));
    for(i=bas;i<=son;i++)
        hedef[i-bas]=kaynak[i];

    hedef[i-bas]='\0';

}
int main()
{
    char metin[]="BÝLGÝSAYAR MUHENDÝSLÝGÝ";
    char *kopya;
    kopyala(metin,kopya,5,9);
    puts(kopya);
    return 0;
}
*//*
int main()
{
    char abcd[]="abcd";
    int i,j,k=0;
    for(j=4; j>=0; j--)
    {
        for(int i=k; i<j; i++)
        {
            printf("%c",abcd[i]);
        }

        printf("\n");

    }

}
*//*
int main()
{
    char dizi[]="BursaTeknikUniversitesi";
    char *str;
    for(str=dizi;*str;str++)
    {

    }
    printf("%d",str-dizi);
}
*//*
int main()
{
    int sayac=0,i,j;
    char dizi[21];
    char *str;
    str=dizi;
    char sesli[10]={'a','e','i','ı','o','ö','u','ü'};
    printf("Girdi: (max 20)");
    gets(dizi);

    for(str=dizi;str<strlen(dizi);str++)
    {
        for(j=0;j<10;j++)
        {
            if(*(str)==sesli[j])
            sayac++;
        }

    }
    printf("%d",sayac);
}*/
/*
int main()
{
    int dizi[20],temp,sayi,i,j;
    printf("eleman sayisini giriniz");//diziyi buyukten kucuge siralayan program
    scanf("%d",&sayi);
    int *str=(int* )malloc(sizeof(int)*sayi);


    for(i=0;i<sayi;i++){
        scanf("%d",&dizi[i]);
    }
    str=dizi;
    for(int i=0;i<sayi;i++){
        for(j=0; j<i; j++){
            if(dizi[i]>dizi[j]){
                temp=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=temp;
            }
        }

    }
        printf("-----------------------------------------------");
        for(int i=0;i<sayi;i++)
            printf("%d\n",str[i]);

}
*/int main()
{
    int n;
    printf("Eleman sayisini giriniz.");
    scanf("%d",&n);
    int dizim[n];
    int *str;
    str=dizim;

    printf("Elemanlari giriniz:");
    for(int i=0;i<n;i++)
    scanf("%d",&str[i]);

    printf("Elemanlarin tersten yazilmiş hali:");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d\t",*(str+i));
    }

}
