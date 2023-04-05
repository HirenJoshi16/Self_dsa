// Program to rotate list by k nodes ~ coded by vHiren
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
    cout<<endl;
}

// Function that creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to rotate list by k ~ O(n) & O(1)
node* rotateList_ByK(node* head, int k){
    // Edge case
    if(!head || !head->next || k == 0){
        return head;
    }
        node* last = head; node* prev;
        long listLength = 1;

        // Iterate list & find last node
        while(last->next != nullptr) listLength++, prev = last, last = last->next;

        // Rotate list once if k is greater than list length
        if(k > listLength){
            last->next = head; prev->next = nullptr;
            return last;
        }
        // Return original list if k is equal to listlength
        if(k == listLength) return head;
        
        long currCount = 1; long count = listLength-k;

        node* kth_prevNode = head;
        // Find kth previous node
        while(currCount != count && kth_prevNode->next != nullptr) currCount++, kth_prevNode = kth_prevNode->next;

    last->next = head; // Link last node to head
    head = kth_prevNode->next; // Set kth node as head
    kth_prevNode->next = nullptr; // Set kth previous node as last node
    
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

    Traversel(head);
    // Function call  
    head = rotateList_ByK(head, 2);
    Traversel(head);

    return 0;
}