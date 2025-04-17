#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BOYUT 8
#define NORMALE 7
#define KAZAN 1
#define KAYBET -1
#define DEVAM 0

int matris[BOYUT+2][BOYUT+2];
char tab[BOYUT+2][BOYUT+2];
int mayinno,y=0;
int bayrak=0;


void alt_tablo_olustur();
void baslangic_tablosu();
void alt_tabloyu_goster();
void ekrana_bastir();
void mayini_yerlestir();
int oyunsonucu();//kazanýp kazanmadýðýný kontrol eder.
void explorer();
int konum_ac(int satir,int sutun);


int main()
{
    int devam,satir,sutun;//konum
    int ilerleme,yeniden;
    int bayrak;
    char action;//hangi harf
    printf("---------------------------------\n\n");
    printf("MAYIN TARLASI OYUNUNA HOSGELDINIZ!!");
    printf("\n\n---------------------------------\n");
    printf("\n\nDevam etmek icin 1 i tuslayin.\n\n");
    scanf("%d",&devam);
    if(devam==1)
    {
        system("cls");
        alt_tablo_olustur();
        baslangic_tablosu();
       // mayini_yerlestir();
    }
    else
    {
        exit(0);
    }
    do
    {
        ekrana_bastir();
        printf("\n\nLutfen su formatlardan birini giriniz:\n-c,satir,sutun\n-d,satir,sutun\n-e,satir,sutun\n\n");
        scanf("%c,%d,%d",&action,&satir,&sutun);
        printf("\n\n");
        if(action=='c')
        {
            ilerleme=konum_ac(satir,sutun);
        }
        else if(action=='d')
        {
            if(mayinno>bayrak)
            {
                bayrak++;
                tab[satir][sutun]='d';
                ilerleme=oyunsonucu();
            }
        }
        else if(action=='e')
        {
            if(bayrak>0)
            {
                bayrak--;
            }
            tab[satir][sutun]='#';
            ilerleme=konum_ac(satir,sutun);
        }
        if(ilerleme==KAYBET)
        {
            system("cls");
            printf("------------------------\n\nOYUM BİTTİ KAYBETTİNİZ!!\n\n------------------------");
            ekrana_bastir();
            //system("cls");
            printf("\n\nOYUNU YENİDEN OYNAMAK İÇİN 1 İ TUSLAYİNİZ.\nOYUNDAN CIKMAK İCİN 0 I TUSLAYİNİZ.\n\n");
            scanf("%d",&yeniden);
            switch(yeniden)
            {
            case 0:
                printf("GOOD BAYY!!");
                return 0;
                break;
            case 1:
                bayrak=0;
                ilerleme=DEVAM;
                alt_tablo_olustur();
                baslangic_tablosu();
                break;
            default:
                printf("\nYANLIS BİR DEGER GİRDİNİZ.\n");
            }
            if(ilerleme==KAZAN)
            {
                printf("------------------------\n\nBRAVO OYUNU KAZANDİNİZ!!\n\n------------------------");
                ekrana_bastir();
                printf("\n\nOYUNU YENİDEN OYNAMAK İÇİN 1 İ TUSLAYİNİZ.\nOYUNDAN CIKMAK İCİN 0 I TUSLAYİNİZ.\n\n");
                scanf("%d",&yeniden);
                switch(yeniden)
                {
                case 0:
                    printf("GOOD BAYY!!");
                    return 0;
                    break;
                case 1:
                    bayrak=0;
                    ilerleme=DEVAM;
                    alt_tablo_olustur();
                    baslangic_tablosu();
                    break;
                default:
                    printf("\nYANLIS BİR DEGER GIRDINIZ.\n");
                }
            }

        }
    }
    while(1);

}

void alt_tablo_olustur()
{
    int i,j,mayinno;

    for(i=0; i<=BOYUT+1; i++)
    {
        for(j=0; j<=BOYUT+1; j++)
        {
            matris[i][j]=0;
        }
    }
    for(i=0; i<=BOYUT+1; i++)
    {
        matris[i][0]=1;
        matris[i][BOYUT+1]=1;
    }
    for(j=0; j<=BOYUT; j++)
    {
        matris[0][j]=1;
        matris[BOYUT+1][j]=1;
    }
    mayinno=NORMALE;
    mayini_yerlestir();
}
void baslangic_tablosu()
{
    int i,j;

    for(i=0; i<=BOYUT+1; i++)
    {
        for(j=0; j<=BOYUT+1; j++)
        {
            tab[i][j]=('#');
        }
    }
    for(i=0; i<=BOYUT+1; i++)
    {
        tab[i][0]='*';
        tab[i][BOYUT+1]='*';
    }
    for(j=0; j<=BOYUT; j++)
    {
        tab[0][j]='*';
        tab[BOYUT+1][j]='*';
    }
}

void ekrana_bastir()
{
    int i,j;
    for(i=1; i<=BOYUT; i++)
    {
        printf("%3d",i);
    }
    printf("\n------------------------\n");
    for(i=1; i<=BOYUT; i++)
    {
        for(j=1; j<=BOYUT; j++)
        {
            printf("%3c",tab[i][j]);
        }
        printf("  |%d",i);
        printf("\n");
    }
    for(i=1; i<=BOYUT; i++)
        printf("---");
}
void mayini_yerlestir()
{
    srand(time(NULL));
    int i,j,k,p,satir,sutun;
    mayinno==NORMALE;
    for(i=1; i<=mayinno; i++)
    {
        satir=1+rand()%BOYUT;
        sutun=1+rand()%BOYUT;
        if(matris[satir][sutun]==-1)
        {
            i--;
        }
        matris[satir][sutun]==-1;
        for(k=-1; k<=1; k++)
        {
            for(p=-1; p<=1; p++)
            {
                if(matris[i][j]==-1 )
                {
                    if(matris[satir+k][sutun+p]!=-1)
                    {
                        matris[satir+k][sutun+p]++;
                    }
                }

            }
        }
    }


}
int konum_ac(int satir,int sutun)
{
    int x=0;
    if(matris[satir][sutun]==-1)
    {
        x=KAYBET;
    }
    else if(matris[satir][sutun]>0)
    {
        tab[satir][sutun]=('0'+matris[satir][sutun]);
        x=oyunsonucu();
        x=DEVAM;

    }
    else
    {
        explorer(satir,sutun);

    }

    return x;
}
void explorer(int satir,int sutun)
{
    int i,j;
    tab[satir+i][sutun+j]='0'+matris[satir+i][sutun+j];

    for(i=-1; i<=1; i++)
    {
        for(j=-1; j<=1; j++)
        {
            if(matris[satir+i][sutun+i]>0 && tab[satir+i][sutun+i]=='#')
            {
                tab[satir+i][sutun+j]='0'+matris[satir+i][sutun+j];
            }
            else if(matris[satir+i][sutun+j]==0 && tab[satir+i][sutun+j]=='#')
            {
                explorer(satir+i,sutun+j);
            }
        }
    }
}

int oyunsonucu()
{
    int i,j,statu;

    for(i=1; i<=BOYUT; i++)
    {
        for(j=1; j<=BOYUT; j++)
        {
            if(tab[i][j]=='d')
            {
                if(matris[i][j]==-1)
                {
                    y++;
                }
            }
        }
    }

    if(y==NORMALE)
    {
        statu=KAZAN;
    }
    else
    {
        statu=DEVAM;
    }
    return statu;
}
