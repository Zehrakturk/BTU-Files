#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
struct Bilgi
{
    char isim[20],tel[11],kullaniciadi[20];
    char soyisim[20],sifre[6],sifretekrari[6],eposta[20];

};
void Kullanici()
{
    printf("KULLANICI GIRISI");
    int size,sonuc;
    static int adet=0;
    struct Bilgi k1;
    int sifre[6];
    char kullaniciadi[20],satir;
BAS:
    printf("\nKULLANICI ADI:");
    scanf("%s",&kullaniciadi);
    printf("SIFRE :");
    int i=0;
    char ch;
    ch=getch();
    while(ch!=13)//13 enter a basana kadar
    {
        sifre[i]=ch;
        printf("  *  ");
        ch=getch();
        i++;
    }
    sifre[i]='\0';
    printf("\n");
    FILE *ptr= fopen("kullanicilar.dat","r+b");
    if(ptr!=NULL)
    {
        while((fread(&k1,sizeof(struct Bilgi),1,ptr)) != NULL);
        {
            if(strcmp(kullaniciadi,k1.kullaniciadi)==0 && strcmp(sifre,k1.sifre)==0)
            {
                printf("GIRIS BASARILI.");
                printf("Hosgeldiniz. %s %s\n",k1.isim,strupr(k1.soyisim));
                sonuc=1;
            }
        }
    }
    else
    {
        printf("Veritabani erisim hatasi !!! \n");
    }
    if(sonuc==0)
    {
        printf("Kullanici adi veya sifre hatali !!!\n");
        adet++;
        if(adet==3)
        {
            printf("Cok sayida basarisiz giris denemesi yaptiniz!!!\n");
            return 0;
        }
        goto BAS;
    }
}
void Yeniuye()
{
    printf("YENI UYE GIRISI\n\n");
    struct Bilgi k1;
    int i,sonuc=0,boyut,boyut1;
    printf("Isim: ");
    scanf("%s",&k1.isim);
    printf("Soyisim :");
    scanf("%s",&k1.soyisim);
TEL:
    printf("Tel :");
    scanf("%s",&k1.tel);
    boyut1=strlen(k1.tel);
    if(boyut1!=11)
    {
        printf("Telefon numaraniz 11 haneli olmalidir.");
        goto TEL;
    }
KULLANICI:
    printf("Kullanici adi :");
    scanf("%s",&k1.kullaniciadi);
    boyut=strlen(k1.kullaniciadi);
    char a = k1.kullaniciadi[i];
    for(i=0; i<boyut ; i++)
    {
        if(isupper(k1.kullaniciadi[i]))
        {
            sonuc=1;
        }
        if(islower(k1.kullaniciadi[i]))
        {
            sonuc=1;
        }
        else
        {
            sonuc=0;
            printf("Kullanici adiniz basariyla olusturuldu.\n");
            break;
        }
    }
    if(sonuc==1)
    {
        printf("Kullanici adiniz en az bir buyuk harf ve kucuk harf icermelidir!!\n");
        goto KULLANICI;

    }
    printf("E posta adresiniz:___________@gmail.com\n");
    scanf("%s",&k1.eposta);
SIFRE:
    printf("\nsifre:\n");
    i=0;
    char ch;
    ch=getch();
    while(ch!=13)//13 enter a basana kadar
    {
        k1.sifre[i]=ch;
        printf("  *  ");
        ch=getch();
        i++;
    }
    k1.sifre[i]='\0';
    printf("\nsifre tekrar:\n");
    i=0;
    ch;
    ch=getch();
    while(ch!=13)//13 enter a basana kadar
    {
        k1.sifre[i]=ch;
        printf("  *  ");
        ch=getch();
        i++;
    }
    printf("\n");
    int n=strlen(k1.sifre);

    if(n<6)
    {
        printf("sifreniz en az 6 karakter içermelidir.");
        goto SIFRE;
    }
    else if(strcmp(k1.sifre,k1.sifretekrari)==1)
    {
        printf("\nsifreler farkli!!\n");
        goto SIFRE;
    }
    else
    {
        FILE *ptr=fopen("kullanicilar.dat","a+b");
        if(ptr!=NULL)
        {
            fwrite(&k1,sizeof(struct Bilgi),1,ptr);
            fclose(ptr);
            printf("UYELIK ISLEMINIZ BASARIYLA TAMAMLANDI.\n\n");
        }
        else
        {
            printf("Yeni kayit yapilamadi!!!");
        }
    }
}
int main()
{
    setlocale(LC_ALL,"Turkish");
    int geridon;
bas:
    while(1)
    {
        //system("cls");
        int secim;
        printf("ANA MENU\n");
        printf("1-Kullanici girisi\n");
        printf("2-Uye ol\n");
        printf("3-CIKIS\n");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            Kullanici();//kullanici girisini kontrol eder.
            break;
        case 2:
            Yeniuye();
            break;
        case 3:
            printf("Programdan cikis yapiliyor!!");
            printf("Ana menüye dönmek için 1 i tuslayiniz.");
            scanf("%d",&geridon);
            if(geridon==1)
            {
                goto bas;
            }
            exit(0);
            break;
        default:
            printf("Yanlis bir secim yaptiniz.");
        }
    }
}
