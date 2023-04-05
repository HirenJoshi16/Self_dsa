// Program to remove all nodes equal to given value ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    long val;
    node* next;
};

// Method to create node and initialize its data - O(1) & O(1)
node* createNode(long val){
    node* newNode = new node;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Method to display list - O(n) & O(1)
void Traversel(node* head){
    if(!head) 
        return;
    cout<<head->val<<" ";
    Traversel(head->next);
}

// #1 Method to remove all nodes equal to given k - O(n) & O(1)
node* removeAllNodesEqualK(node* head, int k) {
    // Edge case
    if(!head) 
        return nullptr;
    
    node* dummynode = createNode(0);
    dummynode->next = head;
    node* currNode = dummynode;

        // Iterate till last node
        while(currNode->next){
            
            // Change links when found 
            if(currNode->next->val == k)
                currNode->next = currNode->next->next;
            else 
                // Update and move to nodes validly
                currNode = currNode->next; 
        }

    head = dummynode->next; // Update head node 
    delete dummynode; // Delete to avoid memory leak problems    

    return head;
}

// #2 Method to remove all nodes equal to given k - O(n) & O(1)
node* removeAllNodesEqualK_2(node* head, int k) {
    // Edge case
    if(!head) 
        return nullptr;
    
    node* dummynode = createNode(0);
    dummynode->next = head;
    node* prevNode = dummynode;
    node* currNode = head;

        // Iterate till last node
        while(currNode){
            
            // Change links when found 
            if(currNode->val == k)
                prevNode->next = currNode->next;
            else 
                // Update previous node correctly
                prevNode = currNode;

            currNode = currNode->next; // Update each time
        }

    head = dummynode->next; // Update head node 
    delete dummynode; // Delete to avoid memory leak problems    

    return head;
}

// Method to delete list - O(n) & O(1)
void freeMemory(node** head){
    node* currNode = *head; node* next;

    // Iterate list and delete each node
    while(currNode){
        next = currNode->next; 
        delete currNode; 
        currNode = next;
    }

    *head = NULL; // After deletion set list as empty 
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(5);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->next = createNode(5);
    Traversel(head); 
    int k = 5; cout<<" |  "<<"k : "<<k<<endl;

    // Method call 
    head = removeAllNodesEqualK(head, k);
    Traversel(head);

    // Deallocate memory
    freeMemory(&head);

    return 0;
}