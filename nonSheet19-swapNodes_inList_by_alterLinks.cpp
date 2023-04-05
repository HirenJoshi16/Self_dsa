// Program to swap nodes by changing links in list ~ coded by vHiren
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

// Function to swap nodes by changing links ~ O(n) & O(1)
node* swapNodes(node* head, int n1Data, int n2Data){
    // Edge case
    if(head == NULL || (head)->next == NULL) return head;

    // In case both nodes are same
    if(n1Data == n2Data) return head;

    node* prevNode1 = NULL; // To track previous node of node1
    node* node1 = head;
    // Tracks node1 for swap and do maintain previous node of it
    while(node1 && node1->data != n1Data){
        prevNode1 = node1; node1 = node1->next;
    }

    node* prevNode2 = NULL; // To track previous node of node2
    node* node2 = head;
    // Tracks node2 for swap and do maintain previous node of it
    while(node2 && node2->data != n2Data){
        prevNode2 = node2; node2 = node2->next;
    }

    // In case node1 or node2 is not in list
    if(node1 == NULL || node2 == NULL) return NULL;

    // If node1 is not head of the list
    if(prevNode1 != NULL)
        prevNode1->next = node2;
    else    
        head = node2; // Make node2 as head

    // If node2 is not head of the list
    if(prevNode2 != NULL)
        prevNode2->next = node1;
    else    
        head = node1; // Make node1 as head

    // Set remaining links for both nodes correctly
    node* tmp = node2->next; node2->next = node1->next; node1->next = tmp;

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
    Traversel(head); 

    // Nodes to be swapped
    int n1Data = 2; int n2Data = 5; 
    // Function call
    head = swapNodes(head, n1Data, n2Data);
    Traversel(head);

    return 0;
}