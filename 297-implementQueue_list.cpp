// Implementation of queue using list
#include <iostream>
#include <malloc.h>
using namespace std;

// Front and rear ends of the queue
struct node *f = NULL;
struct node *r = NULL;
// Basic Template
struct node{
    int data;
    struct node *next;
};

// checks list is full or not
bool isFull(struct node *n){
    if(n == NULL){
        return true;
    }
    return false;
}

// checks list is empty or not 
bool isEmpty(struct node *f){
    if(f == NULL){
        return true;
    }
    return false;
}

// inserts element in the list
void enQueue(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(isFull(n)){
        cout<<"node creation failed";
    }
    else{
        n->data = data;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        r->next=n;
        r=n;
    }
}

// inserts element in the list
int deQueue(void){
    int x = -1;
    node *q = f;
    if(isEmpty(q)){
        cout<<"list underflow";
    }
    else{
        f = q->next;
        int x = q->data;
        free(q);
    }
    return x;
}

// Traverses each node
void traversel(struct node* f){
    if(f == NULL){
        return;
    }
    cout<<f->data<<" ";
    f = f->next;
    traversel(f);
}

//Driver code
int main(){
    // Inserting elements to list
    enQueue(45);
    enQueue(30);
    enQueue(10);
    enQueue(55);
    traversel(f);
    cout<<endl;

    // Removing elements to list
    deQueue();
    traversel(f);
    return 0;
}