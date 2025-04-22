#include <stdio.h>
#include <stdlib.h>

struct ogrenci{

    int ogrno;
    char ad[10];
    char soyad[10];

};

typedef struct ogrenci ogr;

struct node{

    ogr* bilgi;
    node* next;
    node* pre;
};

typedef struct node n;

struct list{

    int count;
    n* head;
    n* rear;
};
typedef struct list LIST;

LIST* CreateList()
{
    LIST* list;
    list = (LIST*)malloc(sizeof(LIST));
    if(list){
        list->head=NULL;
        list->rear=NULL;
        list->count=0;
    }
    return list;
}


void Add(LIST* list,int x){

    if(list->head==NULL){//birinci eleman eklemek
        n* head = (n*)malloc(sizeof(n));
        head->bilgi->ogrno=1;
        head->next=NULL;
        head->pre=NULL;
        list->head=head;
        list->rear=head;
    }
    n* temp=(n* )malloc(sizeof(n));
    temp->bilgi->ogrno=x;
    temp->next=NULL;
    temp->pre=list->rear;
    list->rear->next=temp;
    list->rear=list->rear->next;

}

void Delete(LIST* list, int x){

    n* temp;
    if(list->head->bilgi->ogrno==x){//head ý silmek
        temp=list->head;
        list->head=list->head->next;
        list->head->pre=NULL;
        free(temp);
    }


}

int main(){






}
