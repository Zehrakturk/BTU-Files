#include <stdio.h>
#include <stdlib.h>

int AsalMi(int sayi,int bolen){


    if(sayi==2)
    {
        return 1;
    }

        if(sayi==bolen){
            return 1;
        }
        else if(sayi%bolen==0){
            return 0;

        }
        else{
            bolen++;
            AsalMi(sayi,bolen);
        }

}
void SayiAl(){
    int sayi;
    int bolen=2;
    printf("Bir sayi giriniz\n Cikmak icin 0 a basin.\n");
    printf("-----------------------------------------------\n");
    scanf("%d",&sayi);
        if(sayi!=0)
        {
            int sonuc=AsalMi(sayi,bolen);
            if(sonuc){
                printf("Sayiniz asaldir.\n");
            }
            else{
                printf("Sayiniz asal degildir.\n");
            }
            SayiAl();
        }
        else
            exit;

}

int main()
{
    SayiAl();



}
