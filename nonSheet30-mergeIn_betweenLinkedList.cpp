// Program to merge in between list ~ coded by vHiren
#include <iostream>
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
}

// Prints list elements
void Traversal(node* first){
    while(first != NULL){
        cout<<first->data<<" ";
        first = first->next;
    }
    cout<<"   ";
}

// Function to merge second list in first in given range - O(n) & O(1)
node* mergeInBetween(node* first, int a, int b, node* second){
    // Edge case
    if(!first || !second) return NULL;

    node* prevA = first; // Tracks previous of A
    node* nodeB = first; // Tracks B
    node* curr = first;

    // Iterate and find previous node of A 
    while(curr->next && curr->next->data != a){
        prevA = prevA->next;
        curr = curr->next;
    }
    curr = first;

    // Iterate and find node B
    while(curr->next && curr->data != b){
        nodeB = nodeB->next;
        curr = curr->next;
    }
    // Connect link
    prevA->next = second;

    // Iterate and find last node
    while(second->next) 
        second = second->next;

    // Connect last node correctly
    second->next = nodeB->next;
    
    return first;
}

// Function to delete list
void freeMemory(node** first){
    node* currNode = *first;
    *first = NULL; // Set list as empty first

    // Iterate and delete each node
    while(currNode){
        node* next = currNode->next; 
        delete currNode; 
        currNode = next;
    }
}

// Driver code
int main(){
    // List 1 : Creating, connecting nodes & initializing their data
    node* first = createNode(1);
    first->next = createNode(2);
    first->next->next = createNode(3);
    first->next->next->next = createNode(4);
    first->next->next->next->next = createNode(5);

    // List 2 : Creating, connecting nodes & initializing their data
    node* second = createNode(1000);
    second->next = createNode(1001);
    second->next->next = createNode(1002);

    // Traversal call
    Traversal(first); Traversal(second);
    cout<<endl;

    // Function call
    first = mergeInBetween(first, 2, 4, second);
    Traversal(first);

    // Deallocating memory
    freeMemory(&first); // As second list is merged into it both gets deleted
    return 0;
}