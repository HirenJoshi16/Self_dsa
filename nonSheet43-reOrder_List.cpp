// Program to reorder list ~ coded by vHiren
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

// Method to reverse list - O(n) & O(1)
node* reverseList(node* head){
    node* prev = nullptr;
    node* curr = head;
    node* next;

    // Iterate till end
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Method to reorder list - O(n) & O(1)
void reorderList(node* head){
    // Edge case
    if(!head || !head->next)
        return;

    node* slow = head;
    node* fast = head;
    // Find middle node
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse the second half
    node* secondHead = reverseList(slow->next);
    slow->next = nullptr; // Set the first half

    node* firstHead = head; node* tmp1; node* tmp2;
    // Iterate second half till end
    while(secondHead){
        tmp1 = firstHead->next;
        tmp2 = secondHead->next;

        firstHead->next = secondHead;
        secondHead->next = tmp1;

        firstHead = tmp1;
        secondHead = tmp2;
    }
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
    reorderList(head); Traversel(head);

    // Deallocate memory
    freeMemory(&head);

    return 0;
}