#include <stdlib.h>
#include <math.h>
double standart_sapma_hesapla(double ortalama, double HBN[ ], int N);
int i,j;
void cevap_anahtari_uret(char cevap_anahtari[],int S) {
	int i =0;
    char siklar[6]={'A','B','C','D','E'};
    srand(time(0));
    for(int i=0;i<S;i++) {
        cevap_anahtari[i]=siklar[rand()%5]; }
    cevap_anahtari_yazdir(cevap_anahtari,S);
}
void cevap_anahtari_yazdir(char cevap_anahtari[],int S) {
    printf("CEVAP ANAHTARI:\n");
    for(int i=0;i<S;i++) {
        printf(" %0.3d : %c |",i+1,cevap_anahtari[i]);
        if((i%10==9) && (i!=S-1))//ogrencinin 10. cevabindan sonra bir satir bosluk eger sinav 9 soru ise bosluk birakmasin
        printf("\n");
    }
    printf("\n");
}
void sinavi_uygula(char ogrenci_cevaplari[][100],char cevap_anahtari[],int N,int S,double D,double B) {
    srand(time(0));
    char ihtimaller[5];
    int rastgele;
    int ogrenci_ID=0;

    for(ogrenci_ID=0; ogrenci_ID<N; ogrenci_ID++) {
		for(int i=0; i<S; i++) {
            rastgele=rand()%100;

            if(0<=rastgele && rastgele<(B*100))//bos ihtimalinden az veya esit olacak sekilde bos atiyoruz.
                ogrenci_cevaplari[ogrenci_ID][i]='X';
            else if((100-(D*100)<rastgele) && (rastgele<=99))//dogru ihtimalinden az veya esit olacak sekilde dogru atiyoruz.
                ogrenci_cevaplari[ogrenci_ID][i]=cevap_anahtari[i];
            else {
                switch(cevap_anahtari[i])
                {
                case 'A':
                    ihtimaller[0]='B'; ihtimaller[1]='C'; ihtimaller[2]='D'; ihtimaller[3]='E'; break;
                case 'B':
                    ihtimaller[0]='A'; ihtimaller[1]='C'; ihtimaller[2]='D'; ihtimaller[3]='E'; break;
                case 'C':
                    ihtimaller[0]='A'; ihtimaller[1]='B'; ihtimaller[2]='D'; ihtimaller[3]='E'; break;
                case 'D':
                    ihtimaller[0]='A'; ihtimaller[1]='C'; ihtimaller[2]='B'; ihtimaller[3]='E'; break;
                case 'E':
                    ihtimaller[0]='A'; ihtimaller[1]='C'; ihtimaller[2]='D'; ihtimaller[3]='B'; break;
                default:
                    printf("Program hatasi!!!");
                }
				for(int i=0; i<S; i++)//her ogrencinin cevabini hesaplayinca yazdirmasi icin ogrenci_cevaplari fonksiyonunu burada cagirdim.
                    ogrenci_cevaplari[ogrenci_ID][i]=ihtimaller[rand()%4];
            }
		}
        ogrenci_cevabini_yazdir(ogrenci_cevaplari, ogrenci_ID,S);
	}
}
void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[ ][100], int ogrenci_ID, int S)
{
    printf("\n%d. OGRENCININ CEVAPLARI:\n",ogrenci_ID+1);
    for(i=0;i<S;i++) {
        printf(" %03d:  %c |",i+1,ogrenci_cevaplari[ogrenci_ID][i]);
        if((i%10==9) && (i!=S-1))//ogrencinin 10. cevabindan sonra bir satir bosluk eger sinav 9 soru ise bosluk birakmasin.
            printf("\n");
    }
}
void ogrencileri_puanla(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], double HBN[ ],int N, int S)
{
    int d,b,y;
    for(i=0;i<N;i++) {
        d=0,b=0,y=0;
        for(j=0;j<S;j++) {
            if(ogrenci_cevaplari[i][j]==cevap_anahtari[j])
                d++;
            else if(ogrenci_cevaplari[i][j]=='X')
                b++;
            else
                y++;
        }
        HBN[i]=((100/S)*(d-(0.25*y)));//net sayisi ile her sorunun degerini carparak HBN puaninin buldum.
        if(HBN[i]<0)
            HBN[i]=0;
    }
}
double sinif_ortalamasi_hesapla(double HBN[ ], int N)
{
    double ortalama;
    double toplam;
    for(i=0;i<N;i++)
        toplam+=HBN[i];
    ortalama=toplam/N;
    sinif_duzeyi(ortalama);//sinif duzeyini yazdirmak icin sinif_duzeyi fonksiyonu tanımdaldım ve burada cagirdim.
    standart_sapma_hesapla(ortalama, HBN, N);//ortalama degerini bu fonksiyonun icinde hesapladigim icin standart_sapma_hesapla fonksiyonunu da bu fonsiyonda cagirdim.
}
void sinif_duzeyi(double ortalama)
{
    printf("\nSinif duzeyi:");//ortalamanin hangi aralikta oldugunu belirleyip araliga gore sinif duzeyini yazdirdim.
    if(ortalama>80.0 && ortalama<=100)
        printf("ustun basari" );
    else if(ortalama>70.0 && ortalama<=80)
        printf("Mukemmel");
    else if(ortalama>62.5 && ortalama<=70.0)
        printf("Cok iyi");
    else if(ortalama>57.5 && ortalama<=62.5)
        printf("Iyi");
    else if(ortalama>52.5 && ortalama<=57.5)
        printf("Ortanin ustu");
    else if(ortalama>47.5 && ortalama<=52.5)
        printf("Orta");
    else if(ortalama>42.5&&ortalama<=47.5)
        printf("Zayif");
    else if( ortalama>0 && ortalama<=42.5)
        printf("Kotu");
}
double standart_sapma_hesapla(double ortalama, double HBN[ ], int N)
{
    double kok,std,T_skoru[N];
    for(i=0;i<N;i++) {
        kok+=pow(HBN[i]-ortalama,2);//once kokun icindeki toplam ifadesini hesaplayip kok degiskenine atadim.
    }
    std=sqrt(kok)/N;//sonrasinda kokun icini sqrt fonksiyonu ile hesaplayip ogrenci sayisina boldum.
    printf("\nSinif ortalamasi: %.2lf, standart sapma: %.2lf\n\n",ortalama,std);
    T_skoru_hesapla( ortalama,  HBN,N, std, T_skoru);//ortalamayi yukaridaki fonksiyonun icinde hesapladigimiz icin T_skoru fonksiyonunu da burada cagirdim.
}
void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ])
{
    double a,b;
    int k;
    for(i=0;i<N;i++) {
        T_skoru[i]=(60 + (10*((HBN[i]-ortalama)/std)));//T_skorunu hesapladim.
    }
    for(i=0;i<N;i++) {
            for(j=0,k=0;j<15,k<=30;j+=2,k+=5){
            if(j==0){
                a=0;b=0;
            }
            if(j==2){
                a=10;b=20;
            }
            else if(j==4){
                a=17.5;b=30;
            }
            else if(j==6) {
                a=23.5;b=37.5;
            }
            else if(j==8 ){
                a=27.5;b=42.5;
            }
            else if (j==10) {
                a=32.5; b=47.5;
            }
            else if(j==12){
                a=37.5;b=52.5;
            }
            else if(j==14){
                a=81.0;b=57.5;
            }
            if(ortalama>80.0-a && ortalama<=100-b) {//ortalamanin girdigi araliga gore her ogrencinin harf notunu belirledim.
                if(T_skoru[i]<32+j)
                    printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);//ve her ogrencinin harf notunu yazdirdim.
                if(T_skoru[i]>=32+j && T_skoru[i]<36.99+k)
                    printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
                if(T_skoru[i]>=37+j && T_skoru[i]<41.99+k)
                    printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
                if(T_skoru[i]>=42+j && T_skoru[i]<46.99+k)
                    printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
                if(T_skoru[i]>=47+j && T_skoru[i]<51.99+k)
                    printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
                if(T_skoru[i]>=52+j && T_skoru[i]<56.99+k)
                    printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
                if(T_skoru[i]>=57+j && T_skoru[i]<61.99+k)
                    printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
                if(T_skoru[i]>=62+j && T_skoru[i]<66.99+k)
                    printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
                if(T_skoru[i]>=67+j)
                    printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
            }
        }
    }
}
int main()
{
    int N,S,ogrenci_ID=0;
    double B,D;
    char satir;
    printf("Ogrenci sayisini giriniz(max 100):");
    scanf("%d",&N);
    printf("Soru sayisini giriniz (max 100):");
    scanf("%d",&S);
BAS:
    printf("Bos birakma ihtimalini giriniz (0.0 ~ 1.0):");//dogru ve bos ihtimali bir den buyuk olamaz eger birden buyuk olursa tekrar deger alsin.
    scanf("%lf",&B);
    printf("Dogru cevap verme ihtimalini giriniz (0.0 ~ 1.0):");
    scanf("%lf",&D);
    if(B+D>=1)
    {
        printf("Bos birakma ihtimali ile dogru cevap verme ihtimali 1 den büyük ve esit olamaz!!\nLutfen yeniden deger giriniz.\n");
        goto BAS;
    }
    double HBN[S];
    char cevap_anahtari[S];
    char ogrenci_cevaplari[N][100];
    cevap_anahtari_uret(cevap_anahtari,S);
    sinavi_uygula(ogrenci_cevaplari,cevap_anahtari, N, S, D, B);
    ogrencileri_puanla(ogrenci_cevaplari,cevap_anahtari,  HBN, N, S);
    sinif_ortalamasi_hesapla(HBN, N);
}
