#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n = 10;
int queue[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int rear = 0, front = 0;

void print_queue_status() {
    cout << "|  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |\n";
    cout << "---------------------------------------------------\n";
    for(int i = 0; i < n; i++) {
        if(!i) cout << "|";
        printf(" %2d |", queue[i]);
    }
    cout << "\n";
    printf("rear:%2d, front:%2d\n=============\n", rear, front);
}

void enqueue(int val) {
    rear = (rear + 1) % n;
    if(rear == front) {
        cout << "queue is full\n";
        rear = (rear + n - 1) % n;
    }
    else queue[rear] = val;
    print_queue_status();
}

int dequeue() {
    if(front == rear) cout << "queue is empty\n";
    else {
        front = (front + 1) % n;
        int res = queue[front];
        queue[front] = -1;
        print_queue_status();
        return res;
    }
}

int main() {
    enqueue(10);
    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    enqueue(17);
    enqueue(18);
    enqueue(19);
    enqueue(20);
    enqueue(21);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(9);
    return 0;
}