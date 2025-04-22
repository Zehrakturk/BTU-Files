#include <stdio.h>
#include <stdlib.h>

struct node{

    int kacinci;
    float b;
    struct node* next;
};
typedef struct node NODE;

void bastir(NODE* list);
void sonaekle(NODE *iter)
{
    while(iter->next!=NULL){
        iter=iter->next;
    }
    iter->next=(NODE*)malloc(sizeof(NODE));
    iter->next->kacinci=4;
    iter->next->next=NULL;
}

void arayaekle(NODE* node,int x, int nereye){

    NODE* gecici;
    gecici=(NODE*)malloc(sizeof(NODE));//bunu unutmaaa
    int kacinci=0;
    while(kacinci!=nereye){
        node=node->next;
        kacinci++;
    }
    gecici->next=node->next;

    node->next=(NODE*)malloc(sizeof(NODE));
    node->next->kacinci=x;
    node->next->next=gecici->next;

}

void siraliekle(NODE* node,int x){

    NODE* ekle;
    ekle=(NODE*)malloc(sizeof(NODE));
    ekle->kacinci=x;
    ekle->next=NULL;
    if(node->kacinci>x){
        ekle->next=node;
        printf("ekledim");
    }
    else if(node->kacinci<x){
        NODE* iter;
        while(iter->next!=NULL || iter->next->kacinci<x){
            iter=iter->next;
        }
        node=node->next;
        siraliekle(node,x);
    }

}
int main()
{
    NODE* node;
    node = (NODE*)malloc(sizeof(NODE));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // or handle the error in an appropriate way
    }

    node->kacinci=1;
    node->next = (NODE*) malloc(sizeof(NODE));
    node->next->kacinci=2;
    node->next->next=(NODE*) malloc(sizeof(NODE));
    node->next->next->kacinci=3;
    node->next->next->next=NULL;//bunu yazmayýnca yazdýrma iþlemi adreslerden devam ediyor.

    NODE* iter;
    iter = node;
    //sonaekle(node);
    //arayaekle(node,100,1);
    siraliekle(node,101);
    siraliekle(node,345);
    siraliekle(node,200);
    bastir(node);


    return 0;

}

void bastir(NODE* iter)
{
    while(iter!=NULL){
        printf("%d",iter->kacinci);
        iter=iter->next;
}


}
