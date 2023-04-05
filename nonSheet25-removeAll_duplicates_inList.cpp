// Program to remove all duplicates from sorted list ~ coded by vHiren
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
    newNode->next = NULL;
    return newNode;
}

// Prints list - O(n) & O(1)
void Traversel(node* head){
    if(!head) 
        return;
    cout<<head->val<<" ";
    Traversel(head->next);
}

// Method to remove all duplicates in list - O(n) & O(1)
node* removeAllDuplicates(node* head){
    // Edge case
    if(!head || !head->next) return head;

    node* dummynode = createNode(0);
    dummynode->next = head;
    node* prev = dummynode; 

    // Iterate list till end
    while(head){

        // If its beginning of sublist of duplicates
        if(head->next && head->val == head->next->val){    
            // Skip all the duplicates and reach its last node
            while(head->next && head->val == head->next->val)
                head = head->next;

            // Set previous node link correctly
            prev->next = head->next;
        }
        // If Beginning of sublist of duplicates had not started
        else{
            prev = prev->next; // Move previous 
        }
        head = head->next; // Move to each node

    }
    return dummynode->next;
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
    *head = NULL; 
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    Traversel(head); cout<<endl<<endl;

    // Method call
    head = removeAllDuplicates(head);
    Traversel(head);

    // Method call
    freeMemory(&head);

    return 0;
}