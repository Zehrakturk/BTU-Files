#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
void menu()
{
    printf("***************************\n");
    printf("* OLASILIK DENEY PROGRAMI *\n");
    printf("***************************\n");
    printf("[1] Zar Deneyi\n");
    printf("[2] Para Deneyi\n");
    printf("Deney Numarasi : ");
}
void zar()
{
    double sayi,i,k,tut,devam;
    double olasilik,kac;
    int c;
    while(1)
    {
        k=0;
        printf("\nZar Kac Kere Atilsin? : ");
        scanf("%lf",&i);
        tut=i;
basla:
        printf("Zarin Kac Gelme Olasiligi Olculsun? [1,2,3,4,5,6]: ");
        scanf("%lf",&kac);
        if(kac<1 || kac>6)
        {
            printf("Lutfen gecerli bir sayi giriniz!!!\n");
            goto basla;
        }
        srand(time(NULL));
        while(i!=0)
        {
            sayi=rand()%6+1;
            printf("Gelen Zar : %1.0lf\n",sayi);
            if(sayi==kac) k+=1;
            i--;
        }
        printf("\n");
        printf("%c",201);
        for(c=0; c<35; c++)
        {
            printf("%c",205);
        }
        printf("%c\n",187);
        printf("%cZarin %1.0lf Gelme Olasiligi : %lf %c\n",186,kac,(k/tut),186);
        printf("%c",200);
        for(c=0; c<35; c++)
        {
            printf("%c",205);
        }
        printf("%c\n",188);
        printf("Deney Tekrarlansin mi? Evet[1] - Hayir[0] : ");
        scanf("%lf",&devam);
        printf("\n");
        if(devam==1) continue;
        else break;
    }
}
void para()
{
    double sayi,i,k,tut,devam;
    double olasilik,gelen;
    int c;
    while(1)
    {
        k=0;
        printf("\nPara Kac Kez Atilsin : ");
        scanf("%lf",&i);
        tut=i;
basla:
        printf("Paranin Ne Gelme Olasiligi Olculsun? TURA[1] - YAZI[0] : ");
        scanf("%lf",&gelen);
        if(gelen!=0 && gelen!=1)
        {
            printf("Lutfen gecerli bir sayi giriniz!!!\n");
            goto basla;
        }
        srand(time(NULL));
        while(i!=0)
        {
            sayi=rand()%2;
            if(sayi==1) printf("Gelen : TURA\n");
            else printf("Gelen : YAZI\n");
            if(sayi==gelen) k+=1;
            i--;
        }
        printf("\n");
        printf("%c",201);
        for(c=0; c<32; c++)
        {
            printf("%c",205);
        }
        printf("%c\n",187);
        if(gelen==1) printf("%cTura Gelme Olasiligi : %lf %c\n",186,(k/tut),186);
        if(gelen==0) printf("%cYazi Gelme Olasiligi : %lf %c\n",186,(k/tut),186);
        printf("%c",200);
        for(c=0; c<32; c++)
        {
            printf("%c",205);
        }
        printf("%c\n",188);
        printf("Deney Tekrarlansin mi? Evet[1] - Hayir[0] : ");
        scanf("%lf",&devam);
        printf("\n");
        if(devam==1) continue;
        else break;
    }
}
void main()
{
    int menum;
    while(1)
    {
        menu();
        scanf("%i",&menum);
        if(menum==1) zar();
        if(menum==2) para();
        else printf("\nLutfen [1] yada [2] tuslayin!!!\n\n");
    }
}
*/

void main(){

    int Hpara[1,101];//100 farklý para
    int i=1;
    for(double ptura=0;ptura<1;ptura+=0.01){
        Hpara[1,i]=(-ptura* log2(ptura) + (1—ptura)* log2(1—ptura) ) ;//entropy formülü
        i++;
    }

    for(i=1;i<101;i++ ){
        printf("para entropy leri:   %ld",Hpara[1,i]);
    }


}
