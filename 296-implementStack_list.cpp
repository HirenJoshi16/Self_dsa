// Implementation of stack using linked list
#include <iostream>
#include <malloc.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node *next;
};

// checks list is full or not
bool isFull(struct node *top){
    if(top == NULL){
        return true;
    }
    return false;
}

// checks list is empty or not 
bool isEmpty(struct node *top){
    if(top == NULL || top->next == NULL){
        return true;
    }
    return false;
}

// inserts element in the list
struct node* push(struct node *top, int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(isFull(n)){
        cout<<"node creation failed";
    }
    else{
        n->data = data;
        n->next = top;
        top = n;
    }
    return top;
}

// inserts element in the list
struct node* pop(struct node *top){
    if(isEmpty(top)){
        cout<<"list underflow";
    }
    else{
        struct node* tmp = top;
        top = top->next;
        free(tmp);
    }
    return top;
}

// Traverses each node
void traversel(struct node* top){
    if(top == NULL){
        return;
    }
    cout<<top->data<<" ";
    top = top->next;
    traversel(top);
}

int main(){
    struct node *top = NULL;
    
    // Pushing elements to list
    top = push(top, 45);
    top = push(top, 30);
    top = push(top, 10);
    top = push(top, 55);
    traversel(top);
    cout<<endl;

    // Poping elements to list
    top = pop(top);
    traversel(top);
    return 0;
}