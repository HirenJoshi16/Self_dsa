// Program to reverse list from left to right position(range) ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    long val;
    node* next;
};

// Method that creates node & initializes its data - O(1) & O(1)
node* createNode(long val){
    node* newNode = new node;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

// Prints list - O(n) & O(1)
void Traversel(node* head){
    if(!head) 
        return;
    cout<<head->val<<" ";
    Traversel(head->next);
}

// Method to reverse nodes of left to right position - O(n) & O(1)
node* reverseByRange(node* head, int left, int right){
    // Edge case
    if(!head || !head->next) return head;

    node* prevLeft = NULL; // Its possible that previous of left can be head hence NULL
    node* currNode = head;
    int i;

    // Find previous node of left and left itself
    for(i=1; i<left; i++){
        prevLeft = currNode;
        currNode = currNode->next;
    }
    
    node* reversedTail = currNode; // Tracks tail of reversed list 
    node* reversedHead = NULL; // Tracks head of reversed list initially we dont have this head hence NULL

    // Reverse nodes of left to right
    while(i <= right){
        node* next = currNode->next;
        currNode->next = reversedHead;
        
        reversedHead = currNode;
        currNode = next;
        i++;
    }
    // If previous of left is present or left != 1
    if(prevLeft)
        prevLeft->next = reversedHead;
    // In case previous of left is not present or left == 1
    else
        head = reversedHead;
    
    // Set this tail
    reversedTail->next = currNode;
    
    return head;
}

// Method to remove list - O(n) & O(1)
void freeMemory(node** head){
    node* currNode = *head; node* next;

    // Iterate list and remove each node
    while(currNode){
        next = currNode->next; 
        delete currNode; 
        currNode = next;
    }
    // After removel set list as empty 
    *head = nullptr; 
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    Traversel(head); cout<<endl<<endl;

    // Method call
    head = reverseByRange(head, 2, 5);
    Traversel(head);

    // Method call
    freeMemory(&head);

    return 0;
}