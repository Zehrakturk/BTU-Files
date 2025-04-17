#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int fun(int *k){
      *k+=4;
      return 3 * ( *k ) -1;
}

int main(){
       int i=10, j=10, sum1,sum2;
       sum1= (i / 2) + fun(&i);
       sum2= fun(&j) + (j/2);

       printf("sum1 = %d\n", sum1);
       printf("sum2 = %d\n", sum2);

       return 0;
}

/*

char satir;
int puan;
int  carpmayap()
{
    int cevap,dogru=0;
    int sayi1 =((rand()%9)+1), sayi2=((rand()%9)+1);
    printf("%d x %d = ?\n",sayi1,sayi2);
    scanf("%c",&satir);
    scanf("%d",&cevap);
    //system("cls");
    if(cevap==sayi1*sayi2)
    {
        puan++;
        printf("dogru cevapladiniz\n");
    }
    else
    {

        printf("Yanlis cevapladiniz\n");
    }
}
int bolmeyap()
{
    int i,cevap,dogru=0;
    int sayi1 =((rand()%9)+1), sayi2=((rand()%9)+1);
    printf("%d / %d = ?\n",sayi1,sayi2);
    scanf("%c",&satir);

    scanf("%d",&cevap);
   // system("cls");

    if(cevap==sayi1/sayi2)
    {
        puan++;
        printf("dogru cevapladiniz\n");
    }
    else
    {
        printf("yanlis cevapladiniz.\n");
    }

    if(dogru==1)
    {
        puan++;
    }
}
int cikarmayap()
{
    int i,dogru=0;
    int cevap;

    int sayi1 =((rand()%9)+1), sayi2=((rand()%9)+1);
    printf("%d - %d = ?\n",sayi1,sayi2);

    scanf("%d",&cevap);
    //system("cls");

    if(cevap==(sayi1-sayi2))
    {
        if(cevap<0 && (sayi1-sayi2)<0 && cevap==sayi1-sayi2){
        puan++;
        printf("dogru cevapladiniz.\n");}
    }
    else
    {
        printf("Yanlis cevapladiniz.\n");
    }
}
int toplamayap()
{
    int i,cevap,dogru=0;


    int sayi1 =((rand()%9)+1), sayi2=((rand()%9)+1);
    printf("%d - %d = ?\n",sayi1,sayi2);
    scanf("%c",&satir);

    scanf("%d",&cevap);
   // system("cls");

    if(cevap==sayi1+sayi2)
    {
        puan++;
        printf("dogru cevapladiniz.\n");
    }
    else
    {
        printf("Yanlis cevapladiniz.\n");
    }
}
int main()
{
    system("color 0a");
    char op[4]= {'*','+','-','/'};
    int rastgele,sorusayisi,i;
    char randomop;
    printf("Oyunda kac soru olacak?\n");
    scanf("%d",&sorusayisi);
    srand(time(NULL));
    for(i=0; i<=sorusayisi; i++)
    {

        rastgele=rand()%strlen(op);
        if (op[rastgele]=='*')
        {
            carpmayap();
        }
        else if(op[rastgele]=='/')
        {
            bolmeyap();
        }
        else if(op[rastgele]=='-')
        {
            cikarmayap();
        }
        else
        {
            toplamayap();
        }
    }
    printf("Puaniniz: %d ",puan);
}*//*
int main()
{
    int s1,s2,durum;
    printf("Baslangiz sayisini giriniz.\n");
    scanf("%d",&s1);
    printf("Bitis sayisini giriniz.\n");
    scanf("%d",&s2);

    int i,j;

    for(i=s1; i<s2; i++)
    {
        durum=1;
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                durum=0;
                break;
            }
        }
        if(durum==1 && i!=1)
        {
            printf("%d\t",i);
        }}}
struct ogrenci{
    int no;
    char ad[20];};
    /*
int main()
{
    struct ogrenci o1={0,""};
    int i;
    FILE *dosya;

    if((dosya=fopen("musteriler.txt","w"))==NULL)
    printf("Dosya olusturulamadi.\n");
    else
    {
        for(i=1; i<=100; i++)
        {
            fwrite(&o1,sizeof(struct ogrenci),1,dosya);
        }
        printf("Dosya olusturma islemi tamamlandi.\n");
        fclose(dosya);
    }
    if((dosya=fopen("musteriler.txt","r+"))==NULL)
    printf("Dosya bulunamadi.\n");
    else
    {
        printf("Cikis icin 0 a basin\n");
        printf("Numara(1-100) :"); scanf("%d",&o1.no);
        while(o1.no!=0)
        {
            printf("Ad: ");scanf("%s",o1.ad);
            fseek(dosya,(o1.no-1)*sizeof(struct ogrenci),SEEK_SET);
            fwrite(&o1,sizeof(struct ogrenci),1,dosya);
            printf("Numara(1-100) :"); scanf("%d",&o1.no);
        }
        printf("Dosyaya yazma islemi tamamlandi.\n");
        fclose(dosya);
    }
        if((dosya=fopen("musteriler.txt","r"))==NULL)
    printf("Dosya bulunamadi.\n");
    else
    {
        printf("Numara    -  Ad\n");

        while(!feof(dosya))
        {

            fread(&o1,sizeof(struct ogrenci),1,dosya);
            if(o1.no!=0)
            printf("%d\t%s\n",o1.no,o1.ad);
        }
        printf("Dosyadan okuma islemi tamamlandi.\n");
        fclose(dosya);
    }}
int faktor(int deger)
{
    int i;
    if(deger==1)
    {
        return deger;
    }
    else
    {
        return deger*faktor(deger-1);}}
int main()
{
    int ucakno,yolcusayisi,deger,i,sonuc;
    printf("Ucak numarasini giriniz.\n");
    scanf("%d",&ucakno);
    deger=ucakno/10;

    yolcusayisi=faktor(deger)*5;
    printf("Ucagin alabilecegi yolcu sayisi: %d",yolcusayisi);}

int faktor(int sayi)
{
    int sonuc=1,i;

        for(i=1;i<=sayi;i++)
        {
            sonuc=sonuc*i;
        }
    printf("%d! = %d\n",sayi,sonuc);
}
int main()
{
   int sayi,secim,sayi1,sayi2;
   while(sayi>=0 && sayi<31)
   {
        printf("Bu program girdiginiz sayinin faktoriyelini alir.\n");
        printf("Girdiginiz sayi 0 dan kucuk ve 31 den buyuk olmamalidir.\n");
        scanf("%d",&sayi);
        faktor(sayi);}
*/
/*
int faktoriyel(int sayi)
{
    int sonuc=1,i;

    for(i=1;i<=sayi;i++)
        {
            sonuc*=i;
        }
    return sonuc; }
void faktoriyelBul()
{
    int sayi;
    printf("Bir sayi giriniz\nNot : Girdiginiz sayi 0 dan kucuk ve 12 den buyuk olmamalidir.\n");
    scanf("%d",&sayi);
    if(sayi<0)
    {
        printf("0");
    }
    else if(sayi>12)
    {
        printf("Cok buyuk bir sayi girdiniz.\n");
        printf("Devam etmek icin bir tusa basiniz.\n");
        scanf("%d",&sayi);
        system("cls");
    }
    else
    {
        printf("%d! = %d\n\n\n",sayi,faktoriyel(sayi));

    }
}
int permu(int sayi1,int sayi2)
{
    return faktoriyel(sayi1)/faktoriyel(sayi1-sayi2);
}
int kombinasyon(int sayi1,int sayi2)
{
    return permu(sayi1,sayi2)/faktoriyel(sayi2);
}
int main()
{
    int secim,sayi,sayi2,durum;
    while(durum==0)
    {
        printf("Yapmak istediginiz islem turunu seciniz\n1-faktoriyel hesapla\n2-permutasyon hesapla\n3-kombinasyon hesapl\n4-cikis\n");
        scanf("%d",&secim);
        system("cls");
        printf("%d\n",secim);
        switch(secim)
    {
        case 1:faktoriyelBul();
        break;
        case 2: printf("P(n,r) formatinda iki sayi giriniz.\nNot : r sayisi n sayisindan buyuk olamaz.\n");
                scanf("%d,%d",&sayi,&sayi2);
                if(sayi2>sayi)
                {
                    printf("Hatali sayi girdiniz.\n");
                    printf("Devam etmek icin bir tusa basiniz.\n");
                    scanf("%d",&secim);
                    system("cls");
                }
                else
                {
                    printf("P(%d,%d) = %d\n\n\n",sayi,sayi2,permu(sayi,sayi2));

                }
        break;
        case 3: printf("K(n,r) formatinda iki sayi giriniz.\nNot: r sayisi n sayisindan buyuk olmamalidir.\n");
                scanf("%d,%d",&sayi,&sayi2);
                if(sayi2>sayi)
                {
                    printf("Hatali sayi girdiniz.\n");
                    printf("Devam etmek icin bir tusa basiniz.\n");
                    scanf("%d",&secim);
                    system("cls");
                }
                else
                {
                    printf("K(%d,%d) = %d\n\n\n",sayi,sayi2,kombinasyon(sayi,sayi2));

                }
        break;
        case 4:
            system("cls");
            durum++;
            printf("Programimiz bitmistir.\n\n");
        break;
        default: printf("Seciminiz islem kodlariyla uyusmuyor.\n");
     printf("Devam etmek islem kodlarindan birini giriniz.\n\n");}}}

*/
