// Program to swap nodes in list by given k ~ coded by vHiren
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

// Function to swap nodes from beginning and end by given k ~ O(n) & O(1)
node* swapNodes(node* head, int k){
    // Edge case
    if(!head || !head->next) return head;

    node* curr; node* left; node* right; 
    curr = left = right = head;

    int counter = 1;
    // Iterate list till end
        while(curr){
            // Tracks kth node of beginning
            if(counter<k)
                left = left->next;

            // Tracks kth node of end
            if(counter>k)
                right = right->next;

            curr = curr->next;
            counter++;
        }
    // Swap values of nodes
    int tmp = left->data; left->data = right->data; right->data = tmp;

    return head;
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
    Traversel(head); int k = 2;

    // Function call
    head = swapNodes(head, k);
    Traversel(head);
 
    return 0;
}