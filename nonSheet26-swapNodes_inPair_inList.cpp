// Program to swap nodes in pair in list ~ coded by vHiren
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

// Method to swap nodes in pair in list - O(n) & O(1)
node* swapPairNodes(node* head){
    // Edge case
    if(!head || !head->next) return head;

    node* temp = createNode(0); 
    temp->next = head;
    node* newHead;

    // Set second node as head node if list is not single noded
    if(head->next != nullptr)
        newHead = head->next;    
        
    // Temp->next - If total nodes are even we dont have to go further 
    // Temp->next->next - If total nodes are odd we dont have to go further 
    while(temp->next && temp->next->next){
        node* node1 = temp->next;
        node* node2 = temp->next->next;
        
        // Change links and set nodes correctly
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1; // Update temp each time
    }
    return newHead;
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
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(6);
    head->next->next->next->next->next = createNode(7);
    Traversel(head); cout<<endl<<endl;

    // Method call
    head = swapPairNodes(head);
    Traversel(head);

    // Method call
    freeMemory(&head);
    
    return 0;
}