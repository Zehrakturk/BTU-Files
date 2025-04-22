#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ogrbilgi {
    int numara;
    char ad[20];
    char soyad[20];
    char bolum[30];
    int sinif;
};

typedef struct ogrbilgi ogrb;

struct node {
    struct node* onceki;
    struct node* sonraki;
    ogrb* ogrbilgi;
};

typedef struct node NODE;

typedef struct {
    int count;
    NODE* head;
    NODE* rear;
    NODE* konum;
    int (*compare)(void* veri1, void* veri2);
} LIST;

LIST* CreateLinkList(int (*compare)(void* veri1, void* veri2));
LIST* DestroyLinkedList(LIST* liste);
int addNode(LIST* liste, void* ogr);
bool deleteNode(LIST* liste, void* ogrkey, void** out);
bool searchNode(LIST* liste, void* veri, void** out);
bool displayLinkList(LIST* liste, int nereden, void** out);

static bool _insert(LIST* liste, NODE* onceki, void* ogr);
static void _delete(LIST* liste, NODE* konum, void** out);
static bool _search(LIST* liste, NODE** onceki, NODE** konum, void* veri);

LIST* CreateLinkList(int (*compare)(void* veri1, void* veri2)) {
    LIST* liste;

    liste = (LIST*)malloc(sizeof(LIST));
    if (liste) {
        liste->head = NULL;
        liste->konum = NULL;
        liste->rear = NULL;
        liste->count = 0;
        liste->compare = compare;
    }

    return liste;
}

int compare(void* veri1, void* veri2) {
    int numara1 = ((ogrb*)veri1)->numara;
    int numara2 = ((ogrb*)veri2)->numara;

    if (numara1 < numara2) return -1;
    if (numara1 > numara2) return 1;
    return 0;
}

int addNode(LIST* liste, void* ogr) {
    bool bulundu;
    bool bul;

    NODE* onceki;
    NODE* konum;

    bul = _search(liste, &onceki, &konum, ogr);
    if (bulundu) {
        return 1;
    }

    bulundu = _insert(liste, onceki, ogr);
    if (!bulundu) {
        return (-1);
    }

    return (0);
}

static bool _insert(LIST* liste, NODE* onceki, void* ogr) {
    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));

    if (!newnode) {
        return false;
    }

    newnode->ogrbilgi = ogr;
    newnode->sonraki = NULL;
    newnode->onceki = NULL;

    if (onceki == NULL) {
        newnode->sonraki = liste->head;
        if (liste->head) {
            liste->head->onceki = newnode;
        }
        liste->head = newnode;
        if (liste->count == 0) {
            liste->rear = newnode;
        }
    } else {
        newnode->sonraki = onceki->sonraki;
        newnode->onceki = onceki;

        if (newnode->sonraki != NULL) {
            newnode->sonraki->onceki = newnode;
        } else {
            liste->rear = newnode;
        }
        onceki->sonraki = newnode;
    }
    (liste->count)++;
    return true;
}

bool deleteNode(LIST* liste, void* ogrkey, void** out) {
    bool bul;

    NODE* onceki;
    NODE* konum;

    bul = _search(liste, &onceki, &konum, ogrkey);
    if (bul) {
        printf("Aranan öðrenci numarasý bulundu.\n");
        _delete(liste, konum, out);
        printf("Öðrenci baþarýyla silindi.\n");
    } else {
        printf("Aranan öðrenci numarasý bulunamadý.\n");
    }

    return bul;
}

static bool _search(LIST* liste, NODE** onceki, NODE** konum, void* veri) {
    int result;

    *onceki = NULL;
    *konum = liste->head;

    if (liste->count == 0) {
        printf("Liste boþ.\n");
        return false;
    }

    if ((*liste->compare)(veri, liste->head->ogrbilgi->numara) < 0) {
        *konum = NULL;
        printf("Aranan öðrenci numarasý listede bulunamadý.\n");
        return false;
    }

    if ((*liste->compare)(veri, liste->rear->ogrbilgi->numara) >= 0) {
        *onceki = liste->rear;
        *konum = NULL;
        printf("Aranan öðrenci numarasý listede bulunamadý.\n");
        return false;
    }

    while ((result = (*liste->compare)(veri, (*konum)->ogrbilgi->numara)) >= 0) {
        *onceki = *konum;
        *konum = (*konum)->sonraki;
    }

    if (result == 0) {
        printf("Aranan öðrenci numarasý bulundu.\n");
        return true;
    } else {
        printf("Aranan öðrenci numarasý listede bulunamadý.\n");
        return false;
    }
}


void _delete(LIST* liste, NODE* konum, void** out) {
    *out = konum->ogrbilgi;

    if (konum->onceki == NULL) {
        liste->head = konum->sonraki;
        if (liste->head) {
            liste->head->onceki = NULL;
        }
    } else {
        konum->onceki->sonraki = konum->sonraki;
    }

    if (konum->sonraki == NULL) {
        liste->rear = konum->onceki;
    } else {
        konum->sonraki->onceki = konum->onceki;
    }

    (liste->count)--;
    free(konum);

    return;
}


bool searchNode(LIST* liste, void* veri, void** out) {
    bool bul;

    NODE* onceki;
    NODE* konum;

    bul = _search(liste, &onceki, &konum, veri);
    if (bul) {
        *out = konum->ogrbilgi;
    } else {
        *out = NULL;
    }

    return bul;
}




bool displayLinkList(LIST* liste, int nereden, void** out) {
    if (liste->count == 0) {
        return false;
    }

    if (nereden == 0) {
        liste->konum = liste->head;
        *out = liste->konum->ogrbilgi;
        return true;
    } else {
        if (liste->konum->sonraki == NULL) {
            return false;
        } else {
            liste->konum = liste->konum->sonraki;
            *out = liste->konum->ogrbilgi;
            return true;
        }
    }
}

LIST* DestroyLinkedList(LIST* liste) {
    NODE* deletePtr;

    if (liste) {
        while (liste->count > 0) {
            free(liste->head->ogrbilgi);
            deletePtr = liste->head;
            liste->head = liste->head->sonraki;

            if (liste->head) {
                    liste->head->onceki = NULL; // Yeni eklenen satýr
        }
        (liste->count)--;

        free(deletePtr->ogrbilgi); // Önce öðrenci bilgilerini serbest býrak
        free(deletePtr); // Sonra düðümü serbest býrak
    }
    }
    free(liste); // Listenin kendisini serbest býrak
    return NULL;

}







int main()
{

    int secim;
    void* key;
    void** out;
    LIST* liste = NULL;

    while(1){


    printf("1-Create List\n2-Add Node\n3-Delete Node\n4-Search Node\n5-Display List\n\n");
    scanf("%d", &secim);

    switch (secim) {
        case 0: printf("Programdan cikiliyor");
                exit(0);
        case 1:
            liste = CreateLinkList(compare);
            printf("Liste olusturuldu\n");
            break;
        case 2: {
            char gecici[20];
            ogrb* bilgi = malloc(sizeof(ogrb)); // Yeni bir öðrenci bilgisi için bellek ayýrýn

            printf("AD:");
            scanf("%s", gecici);
            strcpy(bilgi->ad, gecici);

            printf("SOYAD:");
            scanf("%s", gecici);
            strcpy(bilgi->soyad, gecici);

            printf("BOLUM:");
            scanf("%s", gecici);
            strcpy(bilgi->bolum, gecici);

            printf("SINIF:");
            int gecici1;
            scanf(" %d",&gecici1);
            bilgi->sinif = (rand() % 4) + 1;

            printf("NUMARA: 213608590__");
            //bilgi->numara = rand() % 100 + 21360859000;

            bilgi->numara = scanf(" %d",&gecici1);

            addNode(liste, bilgi);
            printf("Node eklendi\n");
            break;
        }
        case 3:
            printf("Silmek istediginiz ogrenci numarasini girin: ");
            int* silinecekNumara;
            scanf("%d", silinecekNumara);
            if (deleteNode(liste, (void*)silinecekNumara, &out)) {
                printf("%d numaralý öðrenci silindi.\n", silinecekNumara);
            } else {
                printf("%d numaralý öðrenci bulunamadý.\n", silinecekNumara);
            }
            break;

        case 4:
            printf("Aranacak ogrenci numarasini girin: ");
            int aranacakNumara;
            scanf("%d", &aranacakNumara);
            if (searchNode(liste, &aranacakNumara, &out)) {
                printf("%d numaralý öðrenci bulundu.\n", aranacakNumara);
            } else {
                printf("%d numaralý öðrenci bulunamadý.\n", aranacakNumara);
            }
            searchNode(liste, 21360859001, out);
            break;
        case 5:
            printf("Liste:\n");
            while (displayLinkList(liste, 0, &out)) {
                ogrb* bilgi = (ogrb*)out;
                printf("Numara: %d, Ad: %s, Soyad: %s, Bolum: %s, Sinif: %d\n", bilgi->numara, bilgi->ad, bilgi->soyad, bilgi->bolum, bilgi->sinif);
            }
            displayLinkList(liste, 5, out);
            break;
        default:
            printf("Geçersiz seçim.\n");
            break;
        }
    }

// Liste üzerinde iþlem yapýldýktan sonra gerekirse belleði serbest býrakýn
//liste = DestroyLinkedList(liste);



}
