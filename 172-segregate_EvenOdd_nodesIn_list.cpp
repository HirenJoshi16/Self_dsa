// Program to segregate even & odd nodes to list ~ O(n) & O(1) ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
};

// Creates node & initializes its data
struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to segregate even and odd nodes
struct node* segregatenodes(struct node* head){
    // Edge case
    if(!head || !head->next) return head;
    
    // Create two dummy nodes
    struct node* dummyEven = createNode(0);
    struct node* dummyOdd = createNode(0);
    // Set even & odd
    struct node* even = dummyEven;
    struct node* odd = dummyOdd;

    // Iterate till end
    while(head != NULL){
        if(head->data % 2 == 0){
            even->next = head;
            even = even->next;
        }
        else{
            odd->next = head;
            odd = odd->next;
        }
        head = head->next;
    }
    // Link even & odd nodes
    even->next = dummyOdd->next; odd->next = NULL;
    // Update head
    head = dummyEven->next;

    // Delete dummy nodes
    delete dummyEven; delete dummyOdd;

    return head;
}

// Displays list elements
void traversel(struct node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Driver code
int main(){
    // List 1
    node* head = createNode(8);
    head->next = createNode(2);
    head->next->next = createNode(4);
    head->next->next->next = createNode(6);
    head->next->next->next->next = createNode(17);
    head->next->next->next->next->next = createNode(15);
    head->next->next->next->next->next->next = createNode(9);

    traversel(head);
    cout<<endl;
    head = segregatenodes(head);
    traversel(head);
    return 0;
}