#include <stdio.h>
#include <stdlib.h>
typedef struct {
    intx;
    char y;
} Nesne;


int main()
{
    /*char isim[]="can";
    FILE *dosya;
    dosya=fopen("can.txt","w");
    fprintf(dosya,"Bu dosya %s nin dosyasidir.",isim);
    fclose(dosya);
    *///---------------------------------------------------------
    /*
    int sayac;
    FILE *tablo;
    tablo=fopen("tablo.txt","w");

    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            fprintf(tablo,"%d * %d =%d\t ",i,j,i*j);
            sayac++;
            if(sayac==5)
            {
                fprintf(tablo,"\n");
                sayac=0;
            }
        }
        fprintf(tablo,"\n");
    }
    fclose(tablo);
    *///--------------------------------------------------------------
    /*
    char isim[20],okul[20],bolum[20];
    printf("Isminizi giriniz.");gets(isim);
    printf("Okulunuzu giriniz.");gets(okul);
    printf("Bolumuzu giriniz.");gets(bolum);

    FILE *dosya;
    dosya=fopen("ogrenci.txt","w");
    if(dosya==NULL)
        printf("Dosya acilamadi.");
    else{
        fprintf(dosya,"%s\t%s\t%s\n",isim,okul,bolum);
    }
    //append moduyla acinca var olan dosyanin uzerine bilgi ekledik.
    printf("Isminizi giriniz.");gets(isim);
    printf("Okulunuzu giriniz.");gets(okul);
    printf("Bolumuzu giriniz.");gets(bolum);

    dosya=fopen("ogrenci.txt","a");
    if(dosya==NULL)
        printf("Dosya acilamadi.");
    else{
        fprintf(dosya,"%s\t%s\t%s\t",isim,okul,bolum);
    }
    fclose(dosya);
    *///------------------------------------------------------
    /*
    FILE *dosya;
    dosya=fopen("merhaba.txt","w");
    fputs("Merhaba dunya!!",dosya);
    fclose(dosya);

    char karakter;
    dosya=fopen("merhaba.txt","r");
    karakter=fgetc(dosya);//dosyadan okunan veriyi bir degiskene atamak zorundayiz.
    printf("Okunan karakter: %c",karakter);
    fclose(dosya);*/

    /*
    FILE *dosya;
    char okunan[20];
    int i=0;
    dosya=fopen("merhaba.txt","r");
    if(dosya==NULL)
        printf("dosya acilamadi.");
    else{
        while(!feof(dosya)){
            fscanf(dosya,"%s ",okunan);
            printf("%s ",okunan);

        }
    }
    fclose(dosya);*/
    //--------------------------------------------------------

    srand(time(NULL));
    Nesne dizi1[10],dizi2[10];

    for(int i=0;i<10;i++){
        dizi1[i].x=rand()%10+1;
        dizi1[i].y=rand()%26+65;
        printf("Nesne%2d: %d, %c\n",i+1,dizi1[i].x,dizi1[i].y);
    }

    FILE *fp;



    fp=fopen("C:\\Users\\Ergun\\Desktop\\Ikili.txt","w+");
    fwrite(dizi1,sizeof(Nesne),10,fp);
    fseek(fp,0,SEEK_SET);
    fread(dizi2,sizeof(Nesne),10,fp);
    fclose(fp);



    for(int i=0;i<10;i++){
    printf("Nesne%2d: %d, %c\n",i+1,dizi2[i].x,dizi2[i].y);
    }
}
