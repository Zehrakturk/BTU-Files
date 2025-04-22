#include <stdio.h>
#include <stdlib.h>

struct Node{
    void* data;
    struct Node* link;

};
int Say(struct Node* iter,int counter){

    if((iter)->link==NULL){
        return counter;
    }
    return Say(iter->link,counter+1);

}
int main()
{
    struct Node* iter;
    struct Node* Head = (struct Node*)(malloc(sizeof(struct Node)));
    Head->data=65;
    Head->link=NULL;
    iter=Head;

    for(int i=0 ; i<10; i++)
    {
        struct Node* newnode=(struct Node*)(malloc(sizeof(struct Node)));
        newnode->data=i;
        newnode->link=NULL;
        if(Head->link==NULL){
            Head->link=newnode;
        }
        iter->link=newnode;
        iter=iter->link;
    }

    int counter=1;
    iter=Head;
    int sonuc=Say(iter,counter);
    printf("%d",sonuc);

    iter = Head->link;
    while (iter != NULL) {
        struct Node* next = iter->link;
        free(iter);
        iter = next;
    }
    free(Head);

    return 0;



}

