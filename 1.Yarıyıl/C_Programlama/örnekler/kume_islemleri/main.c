#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/*
int main(){
    int secim;
    int kume1[max],kume2[max],kume3[max],kume4[100];
    int n1,n2,n3,i;
    do
    {
        printf("\n\nYapmak istediginiz islemi tuslayiniz.\n1-3kume olustur.\n2-kumeleri goruntule.\n3-kume1 ve kume2 yi birlestir.\n4-kume1 ve kume3 u birlestir.\n5-kume2 ve kume3 u birlestir.\n6-kumelerin hepsini birlestir.\n7-programdan cik.\n\n\n\n");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
        {
            printf("Kume1 i olusturun.\nkac elemanli olsun?");
            scanf("%d",&n1);
            for(i=0; i<n1; i++)
            {
                scanf("%d",&kume1[i]);
            }
            printf("Kume2 i olusturun.\nkac elemanli olsun?");
            scanf("%d",&n2);
            for(i=0; i<n2; i++)
            {
                scanf("%d",&kume2[i]);
            }
            printf("Kume3 i olusturun.\nkac elemanli olsun?");
            scanf("%d",&n3);
            for(i=0; i<n3; i++)
            {
                scanf("%d",&kume3[i]);
            }
        }
        break;
        case 2:
        {
            printf("Kume1:");
            for(i=0; i<n1; i++)
            {
                printf("\n%3d",kume1[i]);
            }
            printf("\n");
            printf("\n------\nKume2: ");
            for(i=0; i<n2; i++)
            {
                printf("\n%3d",kume2[i]);
            }
            printf("\n");
            printf("\n------\nKume3:");
            for(i=0; i<n3; i++)
            {
                printf("\n%3d",kume3[i]);
            }
            printf("\n");
            break;
        }
        case 3:
        {
            int i,k;
            for(i=0; i<n1; i++)
            {
                kume4[i]=kume1[i];
            }
            k=i;
            for(i=0; i<n2; i++)
            {
                kume4[k]=kume2[i];
                k++;
            }
            printf("Kume1 ve kume2 nin birlesmis hali:");
            for(i=0; i<k; i++)
                printf("%3d",kume4[i]);

        }
        break;
        case 4:
            {
                int i=0,k=0;
            for(i=0; i<n1; i++)
            {
                kume4[i]=kume1[i];
            }
            k=i;
            for(i=0; i<n3; i++)
            {
                kume4[k]=kume3[i];
                k++;
            }
            printf("\nKume1 ve kume3 nin birlesmis hali:");
            for(i=0; i<k; i++)
                printf("%3d",kume4[i]);
            }
            break;
        case 5:
            {
                int i,k;
            for(i=0; i<n2; i++)
            {
                kume4[i]=kume2[i];
            }
            k=i;
            for(i=0; i<n3; i++)
            {
                kume4[k]=kume3[i];
                k++;
            }
            printf("\nKume2 ve kume3 nin birlesmis hali:");
            for(i=0; i<k; i++)
                printf("%3d",kume4[i]);
            }
            break;
        case 6:
            {
                int i,k,p;
                for(i=0;i<n1;i++)
                {
                    kume4[i]=kume1[i];
                }
                k=i;
                for(i=0;i<n2;i++)
                {
                    kume4[k]=kume2[i];
                    k++;
                }
                p=k;
                for(i=0;i<n3;i++)
                {
                    kume4[p]=kume3[i];
                    p++;
                }
                printf("\nUc kumenin birlesmis hali:\n");
                for(i=0;i<p;i++)
                {
                    printf("%3d",kume4[i]);
                }
            }
            break;
        }
    }while(secim!=7);

}
*/
void olustur(int kume1[])
{
    int i;
    int n;
    kume1[0]=0;
    printf("Kume kac elemanli?");
    scanf("%d",&n);
    printf("Kumenin elemanlari:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&kume1[i]);
    }

    printf("\n------------------------------------------\n");
    kume1[0]=n;

}
void bastir(int kume[])
{
    int i,n;
    n=kume[0];
    for(i=1;i<=n;i++)
    {
        printf("%4d",kume[i]);
    }
    printf("\n------------------------------------------\n");
}
void birlestir(int kume1[],int kume2[],int kume4[])
{
     int i,n;
     kume4[0]=0;
     n=kume1[0];
     for(i=0;i<=n;i++)
     {
         kume4[i]=kume1[i];
     }
     n=kume2[0];

     for(i=1;i<=n;i++)
     {
         if(!uyemi(kume4,kume2[i]))
         {
             kume4[++kume4[0]]=kume2[i];
         }

     }

}
int uyemi(int kume[],int x)
{
    int i,n;
    n=kume[0];
    for(i=1;i<=n;i++)
    {
        if(x==kume[i])
        {
            return 1;
        }
    }
    return 0;
}
void birlestir2(int kume1[],int kume2[],int kume3[],int kume4[])
{
     int i,n;
     kume4[0]=0;
     n=kume1[0];
     for(i=0;i<=n;i++)
     {
         kume4[i]=kume1[i];
     }
     n=kume2[0];

     for(i=1;i<=n;i++)
     {
         if(!uyemi(kume4,kume2[i]))
         {
             kume4[++kume4[0]]=kume2[i];
         }
     }
     n=kume3[0];
     for(i=1;i<=n;i++)
     {
         if(!uyemi(kume4,kume3[i]))
         {
             kume4[++kume4[0]]=kume3[i];
         }
     }

}
void kesisim(int kume1[],int kume2[],int kume4[])
{
    int i,n;
    n=kume1[0];
    kume4[0]=0;
    for(i=1;i<=n;i++)
    {
        if(uyemi(kume2,kume1[i]))
        {
            kume4[++kume4[0]]=kume1[i];
        }
    }
}


int main()
{
    int kume1[MAX],kume2[MAX],kume3[MAX],kume4[MAX];
    int operasyon;
    kume1[0]=kume2[0]=kume3[0]=0;

    do{
         printf("Yapmak istediginiz islemi seciniz.\n0-Programdan cikmak icin o i tuslayin\n1-3 tane kume olusturun.\n2-Kumeleri bastirin\n3-Kume1 ve Kume2 yi birlestirin\n4-Kume2 ve Kume3 u birlestirin.\n5-Kume1 ve Kume3 u birlestirin.\n6-Uc kumeyi birlestirin.\n7-Kesisim kume1 ve kume2\n");
         printf("8-kesisim kume1 ve kume3\n9-kesisim kume2 ve kume3");
         scanf("%d",&operasyon);
         switch(operasyon)
         {
             case 1: printf("Kume 1 i olusturun.\n");
                     olustur(kume1);
                     printf("Kume 2 i olusturun.\n");
                     olustur(kume2);
                     printf("Kume 3 i olusturun.\n");
                     olustur(kume3);
            break;
            case 2: printf("Kume1:");
                    bastir(kume1);
                    printf("Kume2:");
                    bastir(kume2);
                    printf("Kume3:");
                    bastir(kume3);
            break;
        case 3:
            birlestir(kume1,kume2,kume4);
            bastir(kume4);
            break;
        case 4:
            birlestir(kume2,kume3,kume4);
            bastir(kume4);
            break;
        case 5:
            birlestir(kume1,kume3,kume4);
            bastir(kume4);
            break;
        case 6:
            birlestir2(kume1,kume2,kume3,kume4);
            bastir(kume4);
            break;
        case 0:
            printf("Gule gule");
            break;
        case 7:kesisim(kume1,kume2,kume4);
            bastir(kume4);
            break;
        case 8:kesisim(kume1,kume3,kume4);
            bastir(kume4);
            break;
        case 9:kesisim(kume3,kume2,kume4);
            bastir(kume4);
            break;



         }
    }while(operasyon!=0);

}


