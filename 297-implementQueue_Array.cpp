// Implementation of queue using array
#include <iostream>
#include <malloc.h>
using namespace std;

//Basic template
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

// Checks queue is full or not
bool isFull(struct queue *q){
    if(q->r == q->size-1){
        return true;
    }
    return false;
}

// Checks queue is empty or not
bool isEmpty(struct queue *q){
    if(q->f == q->r){
        return true;
    }
    return false;
}

// Inserts element to the queue
void enQueue(struct queue *q, int key){
    if(isFull(q)){
        cout<<"queue overflow";
    }
    else{
        q->r++;
        q->arr[q->r] = key;
    }
}

// Removes element to the queue
void deQueue(struct queue *q){
    if(isEmpty(q)){
        cout<<"queue underflow";
    }
    else{
        q->f++;
        int x = q->arr[q->f];
    }
}

// // Traverses each element
// void traversel(struct queue *q){
//     if(q->r == q->size){
//         return;
//     }
//     cout<<q->arr[q->r]<<" ";
//     q->r++;
//     traversel(q);
// }

// Traverses each element
void traversel(struct queue *q){
    for(int i=q->f+1; i<=q->r; i++){
        cout<<q->arr[i]<<" ";
    }
}

//Driver code
int main(){
    // Creating a queue and allocating its memory dynamically
    struct queue q;
    q.size = 5;
    q.f=q.r = -1;
    q.arr = new int[q.size];

    // Inserting elements to the queue
    enQueue(&q, 45);
    enQueue(&q, 34);
    enQueue(&q, 10);
    enQueue(&q, 30);
    traversel(&q);
    cout<<endl;

    // Deleting elements to the queue
    deQueue(&q);
    deQueue(&q);
    traversel(&q);
    return 0;
}