#include <stdio.h>
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
    //cevap_anahtari dizisini bu fonksiyonda doldurdugum icin bu fonksiyonun hemen ardindan cevap_anahtari_yazdir fonksiiyonunu cagirdim.
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
    int ogrenci_ID=0;//ogrenci_ID 1 ile N arasinda bir sayidir. Ve ogrenci_cevabini_yazdir fonksiyonuna gönderilir.

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
                case 'A'://eger dogru cevap A ise yanlis cevap B,C,D,E den biri olmali.//ihtimaller dizisi dogru cevap olmayan ihtimalleri tutuyor.
                    ihtimaller[0]='B'; ihtimaller[1]='C'; ihtimaller[2]='D'; ihtimaller[3]='E'; break;
                case 'B':
                    ihtimaller[0]='A'; ihtimaller[1]='C'; ihtimaller[2]='D'; ihtimaller[3]='E'; break;
                case 'C':
                    ihtimaller[0]='A'; ihtimaller[1]='B'; ihtimaller[2]='D'; ihtimaller[3]='E'; break;
                case 'D':
                    ihtimaller[0]='A'; ihtimaller[1]='B'; ihtimaller[2]='C'; ihtimaller[3]='E'; break;
                case 'E':
                    ihtimaller[0]='A'; ihtimaller[1]='B'; ihtimaller[2]='C'; ihtimaller[3]='D'; break;
                default:
                    printf("Program hatasi!!!");
                }
				for(int i=0; i<S; i++)
                    ogrenci_cevaplari[ogrenci_ID][i]=ihtimaller[rand()%4];
            }
		}//bir ogrencinin cevabini hesaplayinca yazdirmasi icin ogrenci_cevaplari fonksiyonunu burada cagirdim.
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
                d++;//dogru sayisini d degiskeninde tuttum ve eger ogrencinin cevabi cevap anahtariyla eslesiyorsa arttirdim.
            else if(ogrenci_cevaplari[i][j]=='X')
                b++;//bos sayisini b degiskeninde tuttum ve eger ogrencinin cevabi 'X' e esitse arttirdim.
            else
                y++;//yanlis sayisini da y degiskeninde tuttum.
        }//net sayisi ile her sorunun degerini carparak HBN puaninin buldum.
        HBN[i]=((100/S)*(d-(0.25*y)));//4 yanlis bir dogruyu gotursun diye yanlis sayisini 0.25 ile carptim
        if(HBN[i]<0)
            HBN[i]=0;
}  }
double sinif_ortalamasi_hesapla(double HBN[ ], int N)
{
    double ortalama;
    double toplam;
    for(i=0;i<N;i++)
        toplam+=HBN[i];
    ortalama=toplam/N;//tum HBN puanlarin toplamini N sayisina bolerek ortalamayi buldum.
    sinif_duzeyi(ortalama);//ortalamanin degerini bu fonksiyonda buldugumuz icin sinif_duzeyi fonksiyonunu bu fonksiyonun icinde cagirdim.
    standart_sapma_hesapla(ortalama, HBN, N);
}
void sinif_duzeyi(double ortalama)
{
    printf("\nSinif duzeyi:");
    if(ortalama>80.0 && ortalama<=100)//ortalamanin degerine gore sinif duzeyini yazdirdim.
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
    printf("\nSinif ortalamasi: %.2lf, standart sapma: %.2lf\n",ortalama,std);
    T_skoru_hesapla( ortalama,  HBN,N, std, T_skoru);//ortalamayi yukaridaki fonksiyonun icinde hesapladigimiz icin T_skoru fonksiyonunu da burada cagirdim.
}
void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ])
{
    for(i=0;i<N;i++) {
        T_skoru[i]=(60 + (10*((HBN[i]-ortalama)/std)));//T_skorunu hesapladim.
    }
    for(j=0;j<N;j++) {
	if(ortalama>80.0 && ortalama<=100) {//ortalamanin hangi deger araliginda oldugunu buldum.
         	if(T_skoru[j]<32)
                printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);//her ogrencinin o deger araligina gore harf notunu buldum.
            if(T_skoru[j]>=32 && T_skoru[j]<36.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
            if(T_skoru[j]>=37 && T_skoru[j]<41.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
            if(T_skoru[j]>=42 && T_skoru[j]<46.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
            if(T_skoru[j]>=47 && T_skoru[j]<51.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
            if(T_skoru[j]>=52 && T_skoru[j]<56.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
            if(T_skoru[j]>=57 && T_skoru[j]<61.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
            if(T_skoru[j]>=62 && T_skoru[j]<66.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
            if(T_skoru[j]>=67)
                printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
        }
    else if(ortalama>70.0 && ortalama<=80) {
            if(T_skoru[j]<34)
                printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);
            if(T_skoru[j]>=34 && T_skoru[j]<38.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
			if(T_skoru[j]>=39 && T_skoru[j]<43.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
			if(T_skoru[j]>=44 && T_skoru[j]<48.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
            if(T_skoru[j]>=49 && T_skoru[j]<53.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
            if(T_skoru[j]>=54 && T_skoru[j]<58.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
            if(T_skoru[j]>=59 && T_skoru[j]<63.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
            if(T_skoru[j]>=64 && T_skoru[j]<68.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
            if(T_skoru[j]>=69)
                printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
        }
		else if(ortalama>62.5 && ortalama<=70.0){//her deger araligi icin bu islemi yapmaya devam ettim.
            if(T_skoru[j]<36)
                printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);
            if(T_skoru[j]>=36 && T_skoru[j]<40.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
            if(T_skoru[j]>=41 && T_skoru[j]<45.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
            if(T_skoru[j]>=46 && T_skoru[j]<50.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
            if(T_skoru[j]>=51 && T_skoru[j]<55.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
            if(T_skoru[j]>=56 && T_skoru[j]<60.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
            if(T_skoru[j]>=61 && T_skoru[j]<65.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
            if(T_skoru[j]>=66 && T_skoru[j]<70.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
            if(T_skoru[j]>=71)
                printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
        }
		else if(ortalama>57.5 && ortalama<=62.5){
            if( T_skoru[j]<38)
                printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);
            if(T_skoru[j]>=38 && T_skoru[j]<42.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
            if(T_skoru[j]>=43 && T_skoru[j]<47.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
            if(T_skoru[j]>=48 && T_skoru[j]<52.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
            if(T_skoru[j]>=53 && T_skoru[j]<57.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
            if(T_skoru[j]>=58 && T_skoru[j]<62.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
            if(T_skoru[j]>=63&& T_skoru[j]<67.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
            if(T_skoru[j]>=68 && T_skoru[j]<72.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
            if(T_skoru[j]>=73)
                printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
        }
		else if(ortalama>52.5 && ortalama<=57.5) {
            if(T_skoru[j]<40)
                printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);
            if(T_skoru[j]>=40 && T_skoru[j]<44.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
            if(T_skoru[j]>=45 && T_skoru[j]<49.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
            if(T_skoru[j]>=50 && T_skoru[j]<54.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
            if(T_skoru[j]>=55 && T_skoru[j]<59.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
            if(T_skoru[j]>=60 && T_skoru[j]<64.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
            if(T_skoru[j]>=65 && T_skoru[j]<69.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
            if(T_skoru[j]>=70 && T_skoru[j]<74.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
            if(T_skoru[j]>=75)
                printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
        }
		else if(ortalama>47.5 && ortalama<=52.5){
            if(T_skoru[j]<42)
                printf("%d. ogrencinin HBN: %lf, harf notu FF",j+1,HBN[j]);
            if(T_skoru[j]>=42 && T_skoru[j]<46.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD",j+1,HBN[j]);
            if(T_skoru[j]>=47 && T_skoru[j]<51.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD",j+1,HBN[j]);
            if(T_skoru[j]>=52 && T_skoru[j]<56.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC",j+1,HBN[j]);
            if(T_skoru[j]>=57 && T_skoru[j]<61.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC",j+1,HBN[j]);
            if(T_skoru[j]>=62 && T_skoru[j]<66.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB",j+1,HBN[j]);
            if(T_skoru[j]>=67 && T_skoru[j]<71.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB",j+1,HBN[j]);
            if(T_skoru[j]>=72 && T_skoru[j]<76.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA",j+1,HBN[j]);
            if(T_skoru[j]>=77)
                printf("%d. ogrencinin HBN: %lf, harf notu AA",j+1,HBN[j]);
        }
    	else if(ortalama>42.5&&ortalama<=47.5){
            if(T_skoru[j]<44)
                printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);
            if(T_skoru[j]>=44 && T_skoru[j]<48.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
            if(T_skoru[j]>=49 && T_skoru[j]<53.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
            if(T_skoru[j]>=54 && T_skoru[j]<58.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
            if(T_skoru[j]>=59 && T_skoru[j]<63.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
            if(T_skoru[j]>=64 && T_skoru[j]<68.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
            if(T_skoru[j]>=69 && T_skoru[j]<73.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
            if(T_skoru[j]>=74 && T_skoru[j]<78.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
            if(T_skoru[j]>=79)
                printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
        }
		else if( ortalama>0 && ortalama<=42.5){
            if(T_skoru[j]<46)
                printf("%d. ogrencinin HBN: %lf, harf notu FF\n",j+1,HBN[j]);
            if(T_skoru[j]>=46 && T_skoru[j]<50.99)
                printf("%d. ogrencinin HBN: %lf, harf notu FD\n",j+1,HBN[j]);
            if(T_skoru[j]>=51 && T_skoru[j]<55.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DD\n",j+1,HBN[j]);
            if(T_skoru[j]>=56 && T_skoru[j]<60.99)
                printf("%d. ogrencinin HBN: %lf, harf notu DC\n",j+1,HBN[j]);
            if(T_skoru[j]>=61 && T_skoru[j]<65.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CC\n",j+1,HBN[j]);
            if(T_skoru[j]>=66 && T_skoru[j]<70.99)
                printf("%d. ogrencinin HBN: %lf, harf notu CB\n",j+1,HBN[j]);
            if(T_skoru[j]>=71 && T_skoru[j]<75.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BB\n",j+1,HBN[j]);
            if(T_skoru[j]>=76 && T_skoru[j]<80.99)
                printf("%d. ogrencinin HBN: %lf, harf notu BA\n",j+1,HBN[j]);
            if(T_skoru[j]>=81)
                printf("%d. ogrencinin HBN: %lf, harf notu AA\n",j+1,HBN[j]);
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
    if(B+D>=1){
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
