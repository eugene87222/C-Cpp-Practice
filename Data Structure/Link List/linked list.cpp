#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE* createList(int* input,int size)
{
    NODE *first,*current,*previous;
    int i;
    for(i=0;i<size;i++){
        current=malloc(sizeof(NODE));
        current->data=input[i];
        if(i==0)
            first=current;
        else
            previous->next=current;
        current->next=NULL;
        previous=current;
    }
    return first;
}
void printList(NODE* first)
{
    NODE *node=first;
    if(first==NULL)
        printf("List is empty\n");
    else{
        while(node!=NULL){
            printf("%3d ",node->data);
            node=node->next;
        }
        printf("\n");
    }
}
void freeList(NODE* first)
{
    NODE *current,*tmp;
    current=first;
    while(current!=NULL){
        tmp=current;
        current=current->next;
        free(tmp);
    }
}
NODE* searchNode(NODE* first,int item)
{
    NODE *node=first;
    while(node!=NULL){
        if(node->data==item)
            return node;
        else
            node=node->next;
    }
    return NULL;
}
void insertNode(NODE* node,int item)
{
    NODE *newnode;
    newnode=malloc(sizeof(NODE));
    newnode->data=item;
    newnode->next=node->next;
    node->next=newnode;
}
NODE* deleteNode(NODE* first,NODE* node)
{
    NODE *ptr=first;
    if(first==NULL){
        printf("Nothing to delete\n");
        return NULL;
    }
    if(node==first){
        first=first->next;
    }
    else{
        while(ptr->next!=node)
            ptr=ptr->next;
        ptr->next=node->next;
    }
    free(node);
    return first;
}
NODE* reverseList(NODE* first)
{
    NODE *current,*next,*previous;
    if(first==NULL)
        return NULL;
    else{
        next=first;
        previous=current=NULL;
        while(next!=NULL){
            previous=current;
            current=next;
            next=next->next;
            current->next=previous;
        }
        return current;
    }
}
int main()
{
    int size,i;
    NODE *first,*node;
    printf("How many numbers:");
    scanf("%d",&size);
    int input[size];
    for(i=0;i<size;i++){
        scanf("%d",&input[i]);
    }
    first=createList(input,size);
    printList(first);
    node=reverseList(first);
    printList(node);
    freeList(first);
    return 0;
}
