// Program to find middle to linked list ~ O(n) & O(1) | coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    node* next;
};

// Creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to find middle to list
node* findMiddle(node* head){
    // Edge case
    if(head == NULL || head->next == NULL){
        return head;
    }
    // Create two pointers
    node* slow = head;
    node* fast = head;

    // Iterate list
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Displays elements of list
void Traversel(node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    Traversel(head->next);
}

// Driver code
int main(){
    // List
    node* head = createNode(13);
    head->next = createNode(5);
    head->next->next = createNode(7);
    head->next->next->next = createNode(10);
    Traversel(head);
    cout<<endl;

    // Function call
    node* mid = findMiddle(head);
    if(mid != NULL){
        cout<<"Middle node is : "<<mid->data;
    }
    else{
        cout<<"Something went wrong!";
    }
    return 0;
}