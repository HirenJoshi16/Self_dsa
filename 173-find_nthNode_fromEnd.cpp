// Program to find nth node from end of the list ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    long val;
    node* next;
};

// Function that creates node & initializes its data - O(1) & O(1)
node* createNode(long val){
    node* newNode = new node;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Prints list - O(n) & O(1) | Uses constant space due to tail recursion
void Traversel(node* head){
    if(!head) 
        return;
    cout<<head->val<<" ";
    Traversel(head->next);
}

// Function to find nth node from end of the list - O(n) & O(1)
node* findNthFromEnd(node* head, int n){
    // Edge case
    if(!head) return head;

    node* slow = head; node* fast = head;
    
        // Iterate and find nth node from beginning
        while(n>0 && fast){
            fast = fast->next;
            n--;
        }
        // Iterate and find nth node of end
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

    return slow;
}

// Function to remove list - O(n) & O(1)
void freeMemory(node** head){
    node* currNode = *head; node* next;

    // Iterate list and remove each node
    while(currNode){
        next = currNode->next; 
        delete currNode; 
        currNode = next;
    }
    *head = NULL; // After removel set list as empty 
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

    // Function call
    cout<<(findNthFromEnd(head, 6))->val;

    // Function call
    freeMemory(&head);

    return 0;
}