#include <stdio.h>
#include <stdlib.h>
/*
float topla(float a,float b)
{
    return a+b;
}
float cikart(float a,float b)
{
    return a-b;
}float carp(float a,float b)
{
    return a*b;
}float bol(float a,float b)
{
    return a/b;
}
int main()
{
    float (*ahmet[4])(float,float)={topla,cikart,carp,bol};
    for(int i=0;i<4;i++)
        printf("sonuc :%f\n ",ahmet[i](5,4));
}
*//*
int main()
{
    int N;
    printf("Yaratilacak dizinin eleman sayisi");
    scanf("%d",&N);
    int *pdizi=(int *)calloc(N,sizeof(int));   //int *pdizi=(int* )malloc(sizeof(int)*N);//malloc yerine calloc kullansaydýk bellekteki yeri temizleyip döndürürdü.

    for(int i=0;i<N;i++)
        printf("%d\n",*(pdizi+i));

    int artis_miktari;
    printf(" Diziyi kac eleman büyütmek istersin?");
    scanf("%d",&artis_miktari);

    pdizi=(int *)realloc(pdizi,sizeof(int)*(N+artis_miktari));

    for(int i=0;i<N+artis_miktari;i++)
        printf("%d\n",*(pdizi+i));
}*//*
int main()
{
    int N,toplam=0,flag=0,i;
    int *pdizi;

    while(1)
    {
        printf("Kac boyutlu bir dizi olsun?");scanf("%d",&N);
        if(N==0)
            break;
        if(flag==0)
        {
            pdizi=(int* )malloc(sizeof(int)*N);
            flag++;
        }
        else
        {
            pdizi=(int *)realloc(pdizi,sizeof(int)*N);
        }
        for(int i=0;i<N;i++)
            printf("%d.elemani gir",i+1);scanf("%d",(pdizi+i));

        for(int i=0;i<N;i++)
            toplam+= *(pdizi+i);
        printf("ortalama :%d",toplam/N);
    }
}*//*
char *SubString(char *x,int p,int u)
{
    char *dizi=(char *)calloc(u+1,sizeof(char));
    for(int i=0;i<u+1;i++)
        dizi[i]=x[i+p-1];
    dizi[u]='\0';

    return dizi;
}
int main()
{
    char str[100]="Algoritma ve Programlama";
    int pozition=10,uzunluk=13;
    //printf("metni giriniz:");
    //gets(str);

    char *donen=SubString(str,pozition,uzunluk);
    puts(donen);

}*//*
struct ogr{
    int a;
    int b;
};

void degistir(struct ogr *swap)
{
    int temp;
    temp=swap->a;
    swap->a=swap->b;
    swap->b=temp;

}
int main()
{
    struct ogr ogrenci;
    ogrenci.a=5;
    ogrenci.b=6;

    degistir(&ogrenci);
    printf("a:%d b:%d",ogrenci.a,ogrenci.b);

}*//*
struct kisi
{
    int yas;
    char ad;

};
int main()
{
    struct kisi kisiler[50];
    strcpy(kisiler[0].ad,"Ali");
    strcpy(kisiler[1].ad,"hakan");


    kisi *p=kisiler;
    puts((*(p+1)).ad);
}*//*
int main()
{
    FILE *dosya1,*dosya2;
    dosya1= fopen("test.txt","r");
    dosya2=fopen("testkopya.txt","w");

    char x;
    while(1)
    {
        x=fgetc(dosya1);
        if(x==EOF) break;
        fputc(x,dosya2);

    }
}*/
/*
int main()
{
    FILE *dosya1;
    int sayaclar[26]={};
    dosya1= fopen("test.txt","r");

    char x;
    while(1)
    {
        x=fgetc(dosya1);
        if(x==EOF) break;
        if((x<='a' && x<='z') || (x>='A' && x<='Z'))
            sayaclar[tolowe(x)-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        printf("%c : %d ",97+i,sayaclar[i]);
    }
}*/
int main()
{
    FILE *dosya1;
    dosya1= fopen("test.txt","r+");

    char x;
    while(1)
    {
        x=fgetc(dosya1);
        if(x==EOF) break;
        if(x=='s')
        {
            fseek(dosya1,-1,SEEK_CUR);//dosyadaki o pozisyondan itibaren imleci bir geri getir.SEEK_SET bastan baslatir.SEEK_END son karaktere götürür. ancak end den sonra negatif harfler kullanilmasi gerekir.
            fputc('X',dosya1);break;
        }

    }
}
