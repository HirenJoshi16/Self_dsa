// Program to rotate Dll in group of given size ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    long data;
    node* prev;
    node* next;
};

// Creates node & initializes its data
node* createNode(long data){
    node* n = new node;
    n->prev = NULL;
    n->data = data;
    n->next = NULL;
}

// Prints list elements
void Traversel(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Function to rotate DLL in group by given size ~ O(n) & O(1)
node* rotateDLL_inGroup(node* head, long k){
    // Edge case
    if(!head || !head->next || k<=0)
        return head;

    head->prev = NULL;
    node *curr = head, *temp, *newHead;
    long count = 0;

    // Reversing k nodes for each k set in list
    while(curr != NULL && count < k){
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    // If true, it means we have reversed last k set in list hence no recursive call required 
    if(count >= k){
        node* lastRevNode = rotateDLL_inGroup(curr, k);
        head->next = lastRevNode;

        if(lastRevNode != NULL){
        // It's essential for maintaining prev link else we wont be able to track prev links in list due to broken links
            lastRevNode->prev = head;
        }
    }
    return newHead;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(3);
    head->next = createNode(1);
    head->next->prev = head;
    head->next->next = createNode(2);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(6);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(7);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->prev = head->next->next->next->next;        
    Traversel(head);

    // Function call
    head = rotateDLL_inGroup(head, 4);
    Traversel(head);

    return 0;
}