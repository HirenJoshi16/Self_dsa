#include <iostream>
#include <malloc.h>
using namespace std;

int count=0;
// Basic Template
struct node{
    int data;
    struct node* next;
};

// Deletes middle of list
struct node* deleteMiddle(struct node* head){
    struct node* p = head;
    struct node* q = head->next;

    int i=1;
    while(i < count/2){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    delete q;
    return head;
}

// Traverses each element 
void traversel(struct node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Driver code
int main(){
    // Creating nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));
    struct node* sixth = (struct node*)malloc(sizeof(struct node));

    // Connecting the nodes & initializing their data
    head->data = 3;
    head->next = second;
    count++;

    second->data = 10;
    second->next = third;
    count++;

    third->data = 8;
    third->next = fourth;
    count++;

    fourth->data = 6;
    fourth->next = fifth;
    count++;

    fifth->data = 7;
    fifth->next = sixth;
    count++;

    sixth->data = 20;
    sixth->next = NULL;
    count++;

    traversel(head);
    cout<<endl;
    head = deleteMiddle(head);
    traversel(head);
    return 0;
}