// Program to partition list ~ coded by vHiren
// Question grip - Rearrange the list such that all nodes less than x come before nodes greater than or equal to x
// Follow up - You should preserve the original relative order of the nodes in each of the two partitions
// Self Tip : Which means arrange all the lesser nodes first and then put the remaining nodes as it is as the original list
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

// Prints list - O(n) & O(1)
void Traversel(node* head){
    if(!head) 
        return;
    cout<<head->val<<" ";
    Traversel(head->next);
}

// Function to partition a list - O(n) & O(1)
node* partitionList(node* head, int x) {
    // Edge case
    if(!head || !head->next)
        return head;

    node* lesserNode = createNode(0); // To store lesser nodes 
    node* lesser = lesserNode;

    node* greaterNode = createNode(0); // To store greater nodes or remaining nodes
    node* greater = greaterNode;
    
    // Iterate list till end
    while(head){
        // Seperate list for lesser nodes
        if(head->val < x){
            lesser->next = head;
            lesser = lesser->next;
        }
        // Seperate list for greater nodes or remaining nodes
        else{
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }
    // Connect both the list
    lesser->next = greaterNode->next;
    // Set its last node to NULL
    greater->next = NULL;
    // Set head as we have to free the memory later
    node* newHead = lesserNode->next;

    // Delete both the node to avoid memory leak problems
    delete lesserNode; delete greaterNode;

    return newHead;
}

// Function to delete list - O(n) & O(1)
node* freeMemory(node* head){
    node* currNode = head; node* next;

    // Iterate list and delete each node
    while(head){
        next = currNode->next; 
        delete currNode; 
        currNode = next;
    }
    head = NULL; // After deletion set list as empty 
    return head;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(1);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->next = createNode(0);
    Traversel(head); 
    int x = 5; cout<<" |  "<<"x : "<<x<<endl;

    // Function call 
    head = partitionList(head, x);
    Traversel(head);

    // Deallocate memory
    head = freeMemory(head);

    return 0;
}