#include <stdio.h>
#include <stdlib.h>

int itr=-1,size=-1;
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NODE;
NODE *head;
NODE *GetNewNode(int val){
    NODE *newNode=malloc(sizeof(NODE));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void InsertAtLeft(int val){
    NODE *newNode=GetNewNode(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    NODE *temp=head;
    while(temp->data!=GetItr(itr))
        temp=temp->next;
    if(temp->prev==NULL){
        newNode->next=temp;
        temp->prev=newNode;
        head=newNode;
    }
    temp->prev->next=newNode;
    newNode->next=temp;
    newNode->prev=temp->prev;
    temp->prev=newNode;
}
void InsertAtRight(int val){
    NODE *newNode=GetNewNode(val);
    NODE *temp=head;
    while(temp->data!=GetItr(itr))
        temp=temp->next;
    if(temp->next==NULL){
        newNode->prev=temp;
        temp->next=newNode;
        return;
    }
    temp->next->prev=newNode;
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next=newNode;
}
int GetItr(int index){
    NODE *temp=head;
    int count=0;
    while (temp!=NULL){
       if (count==index)
          return(temp->data);
       count++;
       temp=temp->next;
    }
   return 0;
}
void RemoveNode(int index){
    NODE *bef,*aft,*temp=head;
    int count=0;
    while(count!=index){
        count++;
        temp=temp->next;
    }
    if(temp==head){
        head=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    free(temp);
    size--;
}
void Print(){
    NODE *temp=head;
    printf("List:");
    while(temp!=NULL){
        if(temp==head){
            printf("%d",temp->data);
            temp=temp->next;
        }
        else{
            printf("->%d",temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}
int main()
{
    int oper,val;
    printf("Functions:(1)insert_left (2)insert_right (3)move_left\n%*s(4)move_right  (5)remove_node  (6)print_list\n\n",10,"");
    head=NULL;
    while(1){
        printf("Select functions:");
        scanf("%d",&oper);
        switch(oper){
            case 1:
                printf("Input the value:");
                scanf("%d",&val);
                InsertAtLeft(val);
                itr++; size++;
                printf("Iterator Node%d Value:%d\n\n",itr,GetItr(itr));
                break;
            case 2:
                printf("Input the value:");
                scanf("%d",&val);
                InsertAtRight(val);
                size++;
                printf("Iterator Node%d Value:%d\n\n",itr,GetItr(itr));
                break;
            case 3:
                if(itr-1<0)
                    printf("Cannot move to the left node\n");
                else itr--;
                printf("Iterator Node%d Value:%d\n\n",itr,GetItr(itr));
                break;
            case 4:
                if(itr+1>size)
                    printf("Cannot move to the right node\n");
                else itr++;
                printf("Iterator Node%d Value:%d\n\n",itr,GetItr(itr));
                break;
            case 5:
                if(size<0)
                    printf("Cannot remove node\n");
                else
                    RemoveNode(itr);
                if(itr>size) itr--;
                printf("Iterator Node%d Value:%d\n\n",itr,GetItr(itr));
                break;
            case 6:
                Print();
                printf("Iterator Node%d Value:%d\n\n",itr,GetItr(itr));
                break;
        }
    }
    return 0;
}
