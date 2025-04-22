#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ogrbilgi{

    void* numara;
    char ad[20];
    char soyad[20];
    char bolum[30];
    int sinif;
};
typedef struct ogrbilgi ogrb;

struct node{
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
    int (*compare)(void** veri1,void** veri2);

}LIST;

LIST* CreateLinkList( int(*compare)(void* veri1, void* veri2));
LIST* DestroyLinkedList(LIST* liste);
int addNode(LIST* liste, void* ogrbilgi);
bool deleteNode(LIST* liste, void*** ogrkey, void** out);
bool searchNode(LIST* liste,void** veri, void** out);
bool displayLinkList(LIST* liste, int nereden, void** out);//listcount emptylist, fulllist eksik!!!

static int _insert(LIST* liste,NODE* onceki,void* giris)//NODE* pPre eksik öncekine zaten eriþebilirim tutuyorum.
static void _delete(LIST* liste,NODE* onceki, NODE* konum,void** out);
static bool _search(LIST* liste,NODE** onceki,NODE** konum, void** veri);

LIST* CreateLinkList(int(*compare)(void* veri1,void* veri2))
{
    LIST* liste;

    liste = (LIST*)malloc(sizeof(LIST));
    if(liste){
        liste->head = NULL;
        liste->konum = NULL;
        liste->rear = NULL;
        liste->count=0;
        liste->compare = compare;
    }


    return liste;
}

int addNode(LIST* liste, void** ogrbilgi)
{
    bool bulundu;
    bool bul;


    NODE* onceki;
    NODE* konum;

    bul = _search(liste,&onceki,&konum,&ogr);
    if(bulundu){
        return 1;
    }

    bulundu = _insert(liste, onceki,&ogr);
    if(!bulundu){
        return (-1);
    }

    return(0);

}

static bool _insert(LIST* liste, NODE* onceki,void** ogr ){

    NODE* newnode;
    newnode=(NODE*)malloc(sizeof(NODE));

    if(!newnode){
        return false;
    }

    newnode->ogrbilgi=*ogr;
    newnode->sonraki=NULL;
    newnod->onceki=NULL;

    if(onceki == NULL){
        newnode->sonraki = liste->head;
        newnode->onceki= NULL;
        newnode->ogrbilgi=*ogr;
        liste->head= newnode;
        if(liste->count==0){
            liste->rear=newnode;
        }
    }
    else{
        newnode->sonraki=onceki->sonraki;
        newnode->onceki=onceki;

        if(newnode->sonraki==NULL){
            liste->rear = newnode;
        }
    }
    (liste->count)++;
    return true;

}

bool deleteNode(LIST* liste,void*** ogrkey,void** out){

    bool bul;

    NODE* onceki;
    NODE* konum;

    bul= _search(liste,&onceki,&konum, &&ogrkey);
    if(bul){
        _delete(liste,onceki,konum,out);
    }

    return bul;
}

void _delete(LIST* liste, NODE* onceki,NODE* konum,void** out){

    *out = konum->ogrbilgi;
    if(onceki== NULL){
        liste->head = onceki->sonraki;
        liste ->head->onceki=NULL;
    }
    else{
        onceki->sonraki=konum->sonraki;
    }
    if(onceki->sonraki==NULL){
        liste->read=onceki;
    }
    (liste->count)--;
    free(konum);

    return;
}

bool searchNode (LIST* liste, void** veri,void** out)
{
    bool bul;

    NODE* onceki;
    NODE* konum;

    bul=_search(liste,&onceki,&sonraki,&veri);
    if(found)
        *out= onceki->ogrbilgi->numara;
    else
        *out= NULL;

    return bul;
}

bool _search(LIST* liste,NODE** onceki,NODE** konum,void** veri){

    int result;

    *onceki = NULL;
    *konum = liste->head;
    if(liste->count==0)
        return false;

    if((*liste->compare)(veri,liste->rear->ogrbilgi->numara)){
        *onceki = liste->rear;
        *konum=NULL;
       }
    while((result=(*liste->compare)(veri,(*onceki)->(*veri))){
        *onceki=*konum;
        *konum=(*konum)->sonraki;
    }
    if(result== 0){
        return true;
    }
    else
        return false;


}

bool displayLinkList(LIST* liste, int nereden,void** out ){

    if(liste->count==0){
        return false;
    }

    if(nereden==0){
        liste->konum=liste->head;
        *out=liste->konum->ogrbilgi;
        return true;
    }
    else{
        if(liste->konum->sonraki== NULL){
            return false;
        }
        else{
            liste->konum= liste->konum->sonraki;
            *out=liste->konum->ogrbilgi;
            return true;
        }
    }
}

LIST* DestroyLinkedList(LIST* liste){

    NODE* deletePtr;

    if(liste){
        while(liste->count>0){
            free(liste->head->ogrbilgi);
            deletePtr = liste->head;
            liste->head = liste->head->sonraki;
            //þuan önceki pointerýný kullanmýyorum
            (liste->count)--;

            free(deletePtr);
        }
        free(liste);
    }
    return NULL;
}












int main()
{

}


void Bastir(struct node* node ){

    //printf("%s\n",node->ogrbilgi->ad);
    //printf("%s\n",node->ogrbilgi->soyad);
    printf("%d\n",node->ogrbilgi->numara);
    printf("%s\n",node->ogrbilgi->bolum);
    printf("%d\n",node->ogrbilgi->sinif);
    printf("\n");


}

