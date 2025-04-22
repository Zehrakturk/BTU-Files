#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öðrenci bilgilerini tutmak için bir yapý (struct) oluþturuyoruz
struct Student {
    int numara;
    char ad[50];
    char soyad[50];
    char bolum[50];
    int sinif;
    struct Student *prev;//oncesine erisebilmek icin
    struct Student *next;//dugumun sontasına ulasabilmek icin kullanıcaz
};

//olusturdugumuz dugume yeni ogrenci bilgilerini giricez
struct Student *createStudent(int numara, char ad[], char soyad[], char bolum[], int sinif) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));//dugum icin bellekten yer ayirdik
    newStudent->numara = numara;
    strcpy(newStudent->ad, ad);
    strcpy(newStudent->soyad, soyad);
    strcpy(newStudent->bolum, bolum);
    newStudent->sinif = sinif;
    newStudent->prev = NULL;//oncesine erisebilmek icin
    newStudent->next = NULL;//sonrasina erisebilmel icin
    return newStudent;
}

//bilgileri girilen ogrenciyi cift bagli listeye alicaz
void ekle(struct Student **head, int numara, char ad[], char soyad[], char bolum[], int sinif) {
    struct Student *temp = createStudent(numara, ad, soyad, bolum, sinif); //ekle fonksiyonunu dugume ekle
    temp->next = *head;
    if (*head != NULL) {
        (*head)->prev = temp;
    }
    *head = temp;
    printf("ogrenci eklendi.\n");
}
//numarasini aldigimiz ogrenciyi bagli listeden silme fonksiyonu
void sil(struct Student **head, int numara) {
    struct Student *current = *head;//current gezici silinecek dugumu bulana kadar gezicek
    while (current != NULL) {
        if (current->numara == numara) {
            if (current->prev != NULL) {  //ilk dugum degilse eger silinen dugumun baglarini degistiryoruz
                current->prev->next = current->next;
            } else {//bas elemansa
                *head = current->next;
            }
            if (current->next != NULL) { //egerki son dugum degilse
                current->next->prev = current->prev;
            }
            free(current);//bellekte currenteserbest biraktik
            printf("ogrenci silindi.\n");
            return;
        }
        current = current->next;
    }
    printf("ogrenci bulunamadi.\n");
}


//numarasi verilen ogrenciyi bulana kadar gezicek dugumleri
void ara(struct Student *head, int numara) {
    while (head != NULL) { //
        if (head->numara == numara) {
            printf("ogrenci Bilgileri:\n");
            printf("Numara: %d\n", head->numara);
            printf("Ad: %s\n", head->ad);
            printf("Soyad: %s\n", head->soyad);
            printf("Bolum: %s\n", head->bolum);
            printf("Sinif: %d\n", head->sinif);
            return;
        }
        head = head->next;
    }
    printf("ogrenci bulunamadi.\n");
}

// Tüm öðrenci bilgilerini listelemek için fonksiyon butun dugumleri gezerek hepsini yazdiricak
void listeyiYazdir(struct Student *head) {
    printf("ogrenci Listesi:\n");
    while (head != NULL) {
        printf("Numara: %d, Ad: %s, Soyad: %s, Bolum: %s, Sinif: %d\n",
               head->numara, head->ad, head->soyad, head->bolum, head->sinif);
        head = head->next;
    }
}

int main() {
    struct Student *head = NULL;
    int secim, numara, sinif;
    char ad[50], soyad[50], bolum[50];

    do {//burdaki menumuzun biz 0 secene kadar sormasini istiyoruzz
        printf("\nMENU:\n");
        printf("1. ogrenci Ekle\n");
        printf("2. ogrenci Sil\n");
        printf("3. ogrenci Ara\n");
        printf("4. Listeyi Yazdir\n");
        printf("0. cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Numara: ");
                scanf("%d", &numara);
                printf("Ad: ");
                scanf("%s", ad);
                printf("Soyad: ");
                scanf("%s", soyad);
                printf("Bolum: ");
                scanf("%s", bolum);
                printf("Sinif: ");
                scanf("%d", &sinif);
                ekle(&head, numara, ad, soyad, bolum, sinif);
                break;
            case 2:
                printf("Silinecek ogrencinin numarasi: ");
                scanf("%d", &numara);
                sil(&head, numara);
                break;
            case 3:
                printf("Aranacak ogrencinin numarasi: ");
                scanf("%d", &numara);
                ara(head, numara);
                break;
            case 4:
                listeyiYazdir(head);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Lütfen tekrar deneyin.\n");
        }
    } while (secim != 0);

    return 0;
}
