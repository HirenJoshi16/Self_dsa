// Program to delete nodes having greater value on their right side ~ coded by vHiren
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

// Function that reverses list
void reverseList(node **head){
    node *prev = NULL;
    node *current = *head;
    node *nextPtr;

    while(current!=NULL){
        nextPtr = current->next;
        current->next = prev;

        prev = current;
        current = nextPtr;
    }
    *head = prev;
}

// #1 ~ Deletes nodes having greater value to their right side | O(n) & O(1)
void _deleteNodes_havingGreater1(node* head){
    // Edge case
    if(!head || !head->next)
        return;

    node* curr = head;
    node* maxNode = head;
    node* tmp;

    // If current is smaller than max then delete current node
    while(curr != NULL && curr->next != NULL){
        if(curr->next->data < maxNode->data){
            tmp = curr->next;
            curr->next = tmp->next;
            free(tmp);
        }
        // If current is greater than max then update current node & max
        else{
            curr = curr->next;
            maxNode = curr;
        }
    }
}

// #2 ~ Deletes nodes having greater value to their right side | O(n) & O(1)
void _deleteNodes_havingGreater2(node* head){
    // Edge case
    if(!head || !head->next)
        return;

    node* curr = head;
    // Copying next node data & address to current node ~ Indirectly deleting nodes
    while(curr != NULL && curr->next != NULL){
        if(curr->data < curr->next->data){
            curr->data = curr->next->data;
            curr->next = curr->next->next;
        }
        else{
            // Move current to next node
            curr = curr->next;
        }
    }
}

// Function that deletes nodes having greater to their right
void deleteNodes_havingGreater(node** head){
    // Reversing original list 
    reverseList(head);

    // Deleting nodes having gretear to their right, head node will never get deleted as its the leftmost node
    _deleteNodes_havingGreater1(*head);

    // Reversing list to retain its original order
    reverseList(head);
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data : Test Case 1
    // node* head = createNode(30);
    // head->next = createNode(20);
    // head->next->next = createNode(21);
    // head->next->next->next = createNode(10);
    // head->next->next->next->next = createNode(15);
    // OutPut is : 30   21   15

    // Creating, connecting nodes & initializing their data : Test Case 2
    // node* head = createNode(12);
    // head->next = createNode(15);
    // head->next->next = createNode(10);
    // head->next->next->next = createNode(11);
    // head->next->next->next->next = createNode(5);
    // head->next->next->next->next->next = createNode(6);
    // head->next->next->next->next->next->next = createNode(2);
    // head->next->next->next->next->next->next->next = createNode(3);
    // OutPut is : 15   11   6    3

    // Creating, connecting nodes & initializing their data : Test Case 3
    node* head = createNode(10);
    head->next = createNode(21);
    head->next->next = createNode(25);
    head->next->next->next = createNode(16);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(26);
    head->next->next->next->next->next->next = createNode(31);
    head->next->next->next->next->next->next->next = createNode(10);
    head->next->next->next->next->next->next->next->next = createNode(12);
    // OutPut is : 50   31   12

    // Function call
    Traversel(head);
    deleteNodes_havingGreater(&head);
    Traversel(head);

    return 0;
}