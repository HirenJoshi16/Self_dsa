// Programt to reverse a doubly linked list
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

// Rotates dll by n nodes
struct node* rotatebyN(struct node* head, int n){
    struct node* tmp = head;

    if(n==0){
        return NULL;
    }
    // Move tmp pointer to last node
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    // Now make it a circular list
    tmp->next = head;
    head->prev = tmp;

    int i=1;
    while(i <= n){
        head = head->next;
        tmp = tmp->next;
        i++;
    }
    // Uncircular the list
    tmp->next = NULL;
    head->prev = NULL;
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

// Driver code
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
    head = rotatebyN(head, 3);
    traversel(head);
    return 0;
}