#include <stdio.h>
#include <stdlib.h>

void bastir(int kod)
{
    if(kod==5)
    {
        printf("Seni Seviyorum");
        bastir(kod);
    }
}
int main()
{
    double h;//h sabit(yani haftalik )calisanlarin ucreti
    double n,saatlik,siparis;//n saatlik çalisanlarin 40 saat dolana kadarki geliri
    float a;//saatlik çalisanlarin fazla mesai saati
    int b;//b sipariþ çalisanlarin satis sayisi
    int c;//parça çalisanlarin parça sayisi
    double d;//parça çalisanlarin parça basina geliri
    int kod;




    do{
    printf("Lutfen calisan kodunu giriniz.");
    scanf("%d",&kod);
    switch (kod)
    {
        case 1 :{
         printf("Sabit calisan maasi:\n");
         scanf("%.2lf",&h);
         printf("Calisana odenecek tutar: %lf\n",h);
        }
        break;
        case 2 :{
            printf("Calisanin saatlik maasi:\n");
            scanf("%lf",&n);
            printf("Calisanin mesai saati :\n");
            scanf("%f",&a);
            if(a>40)
               {
                   a-=40;
                   saatlik=40*n+(n*1.5*a);
               }
            else
            {
                saatlik=40*n;
            }
            printf("Calisana odenecek tutar:%lf\n",saatlik);
        }
        break;
        case 3 :{
        printf("Siparis calisaninin satis sayisi:\n");
        scanf("%d",&b);
        siparis=250+(b*0.057);
        printf("Calisana ödenecek tutar: %lf\n",siparis);
        }
        break;
        case 4 :{
        printf("Parca calisaninin parca basina geliri:\n");
        scanf("%lf",&d);
        printf("Calisanin urettigi parca sayisi:\n");
        scanf("%d",&c);
        printf("Calisana odenecek tutar:%lf\n",d*c);
        }
        break;
    }
    }
    while (kod==1||kod==2||kod==3||kod==4);

    bastir(kod);

}
