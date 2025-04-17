#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Hasta
{
    char tc[20];
    char isim[20];
    char soyisim[20];
    char tel[20];
    char adres[20];
    char KlinikNo[20];
    char DoktorNo[20];
    int durum;
};
struct Doktor{
    char isim[20];
    char soyisim[20];
    int KlinikNo;
    int DoktorNo;
};
void HastaKayit()
{

}
void DoktorGiris()
{

}
void DoktorKayit()
{
    system("cls");
    struct Doktor d1 ;
    printf("DOKTOR KAYÝT EKRANÝ\n");
    printf("Isim: "); scanf("%s",&d1.isim);
    printf("Soyisim: "); scanf("%s",&d1.soyisim);
  //  printf("Klinik no: "); scanf("%s",&d1.KlinikNo);
    KlinikSecme();
    printf("\nDoktor No : \n"); scanf("%s",&d1.DoktorNo);
}
void KlinikSecme()
{
    system("cls");
    char karakter='|';
    int secim,i;
    printf("Klinikler :\n");
    for(i=0;i<48;i++)
    {
        printf("-");
    }
    printf("\n1-KBB\n2-Fizik\n3-Cocuk\n4-Noroloji\n5-Dahiliye\n");
    for(i=0;i<48;i++)
    {
        printf("-");
    }
}
int MENU ()
{
    int secim;
    printf("****HASTANE OTOMASYON UYGULAMASINA HOSGELDINIZ****\n\n");
    printf("1- Hasta kayit\n");
    printf("2- Doktor giris \n");
    printf("3- Doktor kayit\n");
    printf("4- Programi KAPAT\n");
    printf("Seciminiz:");scanf("%d",&secim);
    return secim;

}
int main()
{
    int secim=MENU();
    while( secim!=0)
    {
        switch(secim)
        {
        case 1:HastaKayit();break;
        case 2:DoktorGiris();break;
        case 3:DoktorKayit();break;
        case 4:exit(0);break;
        default: printf("HATALI BIR SECIM YAPTINIZ.");exit(0);

        }
    }
    return 0;

}
