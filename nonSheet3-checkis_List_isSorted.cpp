// Program to check list is sorted or not ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    node* next;
};

// Displays elements to list
void Traversel(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Function that creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Checks list is sorted or not ~ O(n) & O(1)
bool isSorted(struct node* head){
    bool sorted = true;

    while(head->next != NULL){
        if(head->data <= head->next->data)
            sorted = true;
        else
            sorted = false;
        head = head->next;
        if(sorted == false)
            return false;
    }
    return true;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(30);
    head->next = createNode(20);
    head->next->next = createNode(21);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(15);
    head->next->next->next->next->next = createNode(45);
    head->next->next->next->next->next->next = createNode(85);
    head->next->next->next->next->next->next->next = createNode(95);
    Traversel(head);
    
    // Function call  
    if(isSorted(head)){
        cout<<"list is sorted";
    }
    else{
        cout<<"list is not sorted";
    }

    return 0;
}