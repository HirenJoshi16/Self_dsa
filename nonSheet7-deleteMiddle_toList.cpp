 // Program to delete middle node to list ~ coded by vHiren
#include <bits/stdc++.h>
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
    cout<<endl;
}

// Function that creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to delete middle to list ~ O(n) & O(1)
node* deleteMiddle(node* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
        // Create two pointers & initialize each to head
        node* slow = head;
        node* fast = head;
        // Create two pointers ~ Will for changing links 
        node* prev = head;
        node* nextt;
    
            // Iterate list to find middle
            while(fast != NULL && fast->next != NULL){
                // Move prev ptr a step less than slow
                (slow == head) ? (0) : (prev = prev->next);
    
                // Move slow & fast
                slow = slow->next;
                fast = fast->next->next;
            }
            // Move & change the links
            nextt = slow->next;
            prev->next = nextt;

        // Delete middle node 
        delete slow;
        slow = head;

    return slow;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(30);
    head->next = createNode(20);
    head->next->next = createNode(21);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(15);
    Traversel(head);

    // Function call
    head = deleteMiddle(head);
    Traversel(head);

    return 0;
}
