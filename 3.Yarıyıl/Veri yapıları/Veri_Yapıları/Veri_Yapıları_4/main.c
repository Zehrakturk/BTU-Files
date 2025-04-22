#include <stdio.h>
#include <stdlib.h>

void Carpanlari(int sayi,int bolen){

    int gecici;
    if(bolen>=sayi){
        exit;
    }
    if(sayi%bolen==0){
        printf("%d\t",bolen);
        gecici=sayi/bolen;
        Carpanlari(gecici,bolen);

    }
    else{
        bolen++;
        Carpanlari(sayi,bolen);
    }

}


int main()
{
    int sayi;
    int bolen=2;
    printf("Bir sayi giriniz\n");
    scanf("%d",&sayi);

    Carpanlari(sayi,bolen);
}
