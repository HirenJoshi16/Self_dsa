// Programt to check is linked list circular or not
#include <iostream>
#include <malloc.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
};

// Checks list is circular or not
bool isCircular(struct node* head){
    struct node *p = head;

        while(p->next != NULL && p->next != head){
            p = p->next;
        }
        if(p->next == head){
            return true;
        }
    return false;
} 

int main(){
    // Creating nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    // Connecting the nodes & initializing their data
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;

    // Function call
    if(isCircular(head)){
        cout<<"list is circular";
    }
    else{
        cout<<"list is not circular";
    }

    return 0;
}