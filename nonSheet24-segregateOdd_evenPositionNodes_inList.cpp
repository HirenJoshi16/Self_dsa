// Program to segregate list as odd and even by position ~ coded by vHiren
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

// Method to segregate list to odd and even by position - O(n) & O(1)
node* segregateOddEven(node* head){
    // Edge case
    if(!head || !head->next) return head;

    node* odd = head;
    node* even = head->next;
    node* evenHead = head->next;

    // Even && Even->next - As we want to handle list such that we want to access whole list without wanting our any member accessing within null pointer
    while(even && even->next){
        odd->next = even->next; // Link odds only
        odd = odd->next;

        even->next = odd->next; // Link evens only
        even = even->next;
    }
    odd->next = evenHead; // Link latest odd to head of evens
        
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

    // Method call
    head = segregateOddEven(head);
    Traversel(head);

    // Method call
    freeMemory(&head);

    return 0;
}