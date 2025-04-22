#include <stdio.h>
#include <stdlib.h>

struct node{

    int x;
    struct node* next;
};
typedef struct node NODE;

void bastir(NODE* r)
{
    NODE* iter = r;
    printf("%d",iter->x);
    iter=iter->next;

    while(iter!=r){
        printf("%d",iter->x);
        iter=iter->next;
    }
    printf("\n");

}

void sonunaekle(NODE* r,int x)
{
    NODE* iter = r;
    while(iter->next!=r){
        iter=iter->next;
    }
    NODE* node;
    node=(NODE*)malloc(sizeof(NODE));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // or handle the error in an appropriate way
    }
    iter->next=node;
    node->next=r;
    node->x=x;
    //printf("%d",iter->x);

}

NODE* eklesirala(NODE* r, int x){

NODE* sil(NODE* r, int x){

    NODE* iter=r;
    if(r->x==x){
        while(iter->next!=r){
            iter=iter->next;
        }
        iter->next=r->next;
        free(r);
        return iter->next;
    }
    while(iter->x!=x && iter->next!=r){
        iter=iter->next
    }
    if(iter->next==r){
        printf("Sayi bulunamadi\n");
        return r;
    }
    temp = iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;
}
    if(r==NULL){
        r=(NODE*)malloc(sizeof(NODE));
        r->next=r;
        r->x=x;
        return r ;
    }
    if(r->x>x){
        NODE* temp =(NODE*)malloc(sizeof(NODE));
        temp->x=x;
        temp->next=r;
        NODE* iter=r;
        while(iter->next!=r){
            iter=iter->next;
        }
        iter->next=temp;
        return temp;
    }
    NODE* iter=r;
    while(iter->!=r && iter->next->x < x ){
        iter=iter->next;
    }
    NODE* temp =(NODE*)malloc(sizeof(NODE));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=x;
    return r;


}
int main(){

    NODE* node;
    node = (NODE*)malloc(sizeof(NODE));
    node->next=node;
    sonunaekle(node,5);
    sonunaekle(node,6);
    bastir(node);


    NODE* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }

    return 0;

}





