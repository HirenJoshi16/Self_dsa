// Implementation of stack using linked list
#include <iostream>
#include <malloc.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node *next;
};
int count;

// checks list is full or not
bool isFull(struct node *top){
    // struct node* n = (struct node*)malloc(sizeof(struct node));
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
        count++;
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

// Finds middle element to the list
struct node* middleNode(struct node* top){
    int i=1;
    struct node* tmp = top;
    while(i != (count/2)+1){
        tmp = tmp->next;
        i++;
    }
    return tmp;
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
    top = push(top, 25);
    traversel(top);
    cout<<endl;

    // Call for finding middle node of the list
    struct node* n = middleNode(top);
    if(n!=NULL){
        cout<<"Middle element is : "<<n->data;
    }
    else{
        cout<<"list is short to find the middle";
    }
    return 0;
}