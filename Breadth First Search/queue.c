#define MAX 50
#include<stdio.h>
#include "queue.h"

int Queue[MAX];
int front=0,rear=0;
int flag=0;
int max=50;

int isfull(){
    if(rear%MAX==rear && flag==1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(){
    if(front==rear && flag==0){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int a){
    if(isfull()){
        printf("Queue is full\n");
        return;
    }
    Queue[rear]=a;
    rear=(rear+1)%MAX;
    if(front==rear) flag=1;
    //printf("Push Success\n");
}

int pop(){
    if(isempty()){
        printf("Queue is empty\n");
        return ' ';
    }
    int tmp=Queue[front];
    Queue[front]=' ';
    front=(front+1)%MAX;
    if(front==rear) flag=0;
    //printf("Pop Success\n");
    return tmp;
}

void printqueue(){
    if(isempty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i=front;
    printf("%c ",Queue[i]);
    i=(i+1)%MAX;
    while(1){
        if(i==rear){
            break;
        }
        printf("%c ",Queue[i]);
        i=(i+1)%MAX;
    }
    printf("\n");
}
