// Coded by vHiren
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

void traversel(node *head){
    node *p = head;
    while(p != NULL){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

// Reverses list by given size ~ O(k) & O(1)
node* reverse(node *head, int k){
    node *prev = NULL;
    node *current = head;
    node *nextPtr;

    int i = 1;
    while(i <= k && current != NULL){
        nextPtr = current->next;
        current->next = prev;

        prev = current;
        current = nextPtr;
        i++;
    }
    // Set head's next to kth next node
    head->next = nextPtr;
    // Set kth node as head node
    head = prev;

    return head;
}

int main(){
    // Creating nodes & allocating memory dynamically
    struct node* head = new node;
    struct node* second = new node;
    struct node* third = new node;
    struct node* fourth = new node;
    struct node* fifth = new node;

    // Connecting the nodes & initializing their data
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    traversel(head);
    cout<<endl;
    head = reverse(head, 3);
    traversel(head);
    return 0;
}