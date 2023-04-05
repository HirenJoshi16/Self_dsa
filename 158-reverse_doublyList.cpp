// Programt to reverse a doubly linked list
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

// Reverses list
struct node* listReverse(struct node* head){
    struct node* curr = head;
    struct node* tmp = NULL;
        
        while(curr != NULL){
            tmp = curr->prev;
            curr->prev = curr->next;
            curr->next = tmp;
            curr = curr->prev;
        }
        // Before changing head, check if list is empty or in case of a single node
        if(tmp != NULL){
            head = tmp->prev;
        }
    return head;
}

// Traverses each node
void traversel(struct node* head){
    struct node *p = head;
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    traversel(head->next);
}

int main(){
    // Creating nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    // Connecting the nodes & initializing their data
    head->data = 10;
    head->next = second;
    head->prev = NULL;

    second->data = 20;
    second->next = third;
    second->prev = head;

    third->data = 30;
    third->next = fourth;
    third->prev = second;

    fourth->data = 40;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 50;
    fifth->next = NULL;
    fifth->prev = fourth;

    traversel(head);
    cout<<endl;
    head = listReverse(head);
    traversel(head);
    return 0;
}