// Program to clone list with next and random pointer ~ coded by vHiren | Can also be done O(n) & O(1) space
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    long data;
    node* next;
    node* random;
};

// Displays elements to list
void Traversel(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Creates node & initializes its data
node* createNode(long data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Creates a clone list
void insertAtTail(node* &cloneHead, node* &cloneTail, long nodeData){
    node* newNode = createNode(nodeData);
    
    // Initialize head
    if(cloneHead == NULL){
        cloneHead = newNode; cloneTail = newNode;
        return;
    }
    else{
        cloneTail->next = newNode;
        cloneTail = newNode;
    }
}

// #1 - Clones list with next and random pointers ~ O(n) & O(n)
node* cloneList(node* head){
    // Edge case
    if(!head || !head->next) return head;

    node* actualHead = head;
    node* cloneHead = NULL; node* cloneTail = NULL;

    // Create a clone list
    while(actualHead != NULL){
        insertAtTail(cloneHead, cloneTail, actualHead->data);
        actualHead = actualHead->next;
    }

    // Create a map
    unordered_map<node*, node*> uMap;

    actualHead = head; 
    node* cloneNode = cloneHead;
    // Inserting nodes in map
    while(actualHead != NULL){
        uMap[actualHead] = cloneNode;
        actualHead = actualHead->next;
        cloneNode = cloneNode->next;
    } 

    actualHead = head;
    cloneNode = cloneHead;
    // Setting random pointers for clone list
    while(actualHead != NULL){
        cloneNode->random = uMap[actualHead->random];
        actualHead = actualHead->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(1); 
    head->next = createNode(2); 
    head->next->next = createNode(3); 
    head->next->next->next = createNode(4); 
    head->next->next->next->next = createNode(5); 
    Traversel(head);

    // Linking random pointers
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head;
    head->next->next->next->next->random = head->next->next;

    // Printing nodes arbitary data of original list
    cout<<head->random->data<<" ";
    cout<<head->next->random->data<<" ";
    cout<<head->next->next->random->data<<" ";
    cout<<head->next->next->next->random->data<<" ";
    cout<<head->next->next->next->next->random->data<<endl;
    cout<<endl;

    // Function call  
    head = cloneList(head);   
    Traversel(head); 

    // Printing nodes arbitary data of clone list
    node* tmp = head; 
    while(tmp != NULL){
        cout<<tmp->random->data<<" "; tmp = tmp->next;
    }
    return 0;
}