// Programt to find pair given sum in dll ~ O(n) & O(1)
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

// Finds pair of given sum ~ O(n) & O(1)
void findPair(struct node* head, int x){
    struct node* first = head;
    struct node* second = head;

    bool found = false;
    // Moving second ptr to last node
    while(second->next != NULL){
        second = second->next;
    }

    // Iterate list - if first & second crosses each other or meets hence its the termination 
    while(first != second && second->next != first){
        if(first->data + second->data == x){
            found = true;
            cout<<"("<<first->data<<", "<<second->data<<")"<<endl;

            first = first->next;
            second = second->prev;
        }
        else{
            if(first->data + second->data < x){
                first = first->next;
            }
            else{
                second = second->prev;
            }
        }
    }
    if(found == false){
        cout<<"no pairs found";
    }
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
    struct node* sixth = (struct node*)malloc(sizeof(struct node));
    struct node* seventh = (struct node*)malloc(sizeof(struct node));

    // Connecting the nodes & initializing their data
    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 4;
    third->next = fourth;
    third->prev = second;

    fourth->data = 5;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 6;
    fifth->next = sixth;
    fifth->prev = fourth;

    sixth->data = 8;
    sixth->next = seventh;
    sixth->prev = fifth;

    seventh->data = 9;
    seventh->next = NULL;
    seventh->prev = sixth;

    traversel(head);
    cout<<endl;
    int x = 7;
    findPair(head, x);
    return 0;
}