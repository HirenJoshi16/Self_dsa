// Program to insert node such list is in ascending order ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
};

// Creates node to list
struct node* createNode(int data){
    struct node* n = new node;
    n->data = data;
    n->next = nullptr;
    return n;
}

// Displays each node
void Traversal(struct node* head){
    if(!head){
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    Traversal(head->next);
}

// Inserts node such list is in ascending order - O(n) & O(1)
struct node* insertNode(struct node* head, int data){
    // Edge case
    if(!head)
        return head;

    struct node* curr = head;
    struct node* next = head->next;
    // When given data is lesser than head's data
    if(head->data > data){
        struct node* newNode = new node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return head;
    }
    else{
        // Iterate till end and insert data at aggregate position
        while(next){
            if(next->data > data){
            struct node* newNode = new node;

                newNode->data = data;
                newNode->next = curr->next;
                curr->next = newNode;
                return head;
            }
            curr = curr->next;
            next = next->next;
        }
    }
    // When given data is greater then last node
    if(curr->data < data){
        struct node* newNode = new node;

        newNode->data = data;
        curr->next = newNode;
        newNode->next = nullptr;
        return head;
    }
}

// Driver code
int main(){
    // Creating, connecting nodes and initializing their data
    struct node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    Traversal(head);
    
    // Method call
    head = insertNode(head, 25);
    Traversal(head);

    return 0;
}