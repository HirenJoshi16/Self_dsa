// Program to delete nodes which have greater value on their right side ~ coded by vHiren 
#include <iostream>
using namespace std;

// Basic Template
struct node{
    int data;
    node* next;
};

// Displays elements to list
void Traversel(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Function that creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to reverse list
node* reverseList(node* head){
    // Create three pointers
    node* prev = NULL;
    node* curr = head;
    node* nextt;

        // Iterate list & change links 
        while(curr != nullptr){
            nextt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextt;
        }
        head = prev; 

    return head;
}

// Function to delete nodes having greater value to their right side - O(n) & O(1)
node* deleteNodes_havingGreater(node* head){
    // Edge case
    if(!head || !head->next) return head;

    // Reverse list
    head = reverseList(head);
    node* curr = head;
    node* maxNode = head;
    node* tmp;

        // Iterate list
        while(curr != nullptr && curr->next != nullptr){
            // Delete current's next node if its smaller than current
            if(curr->next->data < maxNode->data){
                tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;
            }
            else{
                curr = curr->next;
                maxNode = curr;
            }
        }
        // Retain list original order
        head = reverseList(head);

    return head;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data : Test Case 1
    node* head = createNode(30);
    head->next = createNode(20);
    head->next->next = createNode(21);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(15);
    // OutPut is : 30   21   15

    // Function call
    Traversel(head);
    cout<<endl;
    head = deleteNodes_havingGreater(head); 
    Traversel(head);

    return 0;
}