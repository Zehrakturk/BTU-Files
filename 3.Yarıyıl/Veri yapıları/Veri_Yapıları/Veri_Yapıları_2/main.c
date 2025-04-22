#include <stdio.h>
#include <stdlib.h>

int ThisIsPolidrom(char* kelime,int* baslangic, int* bitis){

    if(*baslangic>=*bitis){
        return 1;
    }

    if((kelime)[*baslangic]!=(kelime)[*bitis]){
        return 0;
    }
    (*baslangic)++;
    (*bitis)--;
    return ThisIsPolidrom(kelime,&baslangic,&bitis);

}

int main()
{
    char kelime[20];
    printf("Bir kelime yaziniz\n");
    scanf("%s",kelime);

    size_t lenght = strlen(kelime);
    int baslangic=0;
    int bitis=lenght-1;

    int sonuc = ThisIsPolidrom(kelime,&baslangic,&bitis);

    if (sonuc) {
        printf("Girilen kelime bir palindromdur.\n");
    } else {
        printf("Girilen kelime bir palindrom degildir.\n");
    }




}
