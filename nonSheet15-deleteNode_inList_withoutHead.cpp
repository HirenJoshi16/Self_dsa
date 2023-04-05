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
    cout<<endl;
}

// Function that creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to delete given node to list without head ~ O(1) & O(1)
bool deleteNode_withoutHead1(node* currNode){
    // Edge case
    if(!currNode->next || !currNode){
        return false;
    }
    // Set nextNode to given node's next because as we know given node is not last node, so nextNode will not be null
    node* nextNode = currNode->next;
    currNode->data = nextNode->data;
    // Reset given node's next to its next->next
    currNode->next = nextNode->next;

    // Set & delete node
    nextNode->next = NULL;
    delete (nextNode);

    return true;
}

// Function to delete given node to list without head ~ O(n) & O(1)
bool deleteNode_withoutHead2(node* currNode){
    // Edge case
    if(!currNode->next || !currNode){
        return false;
    }

    node* prev;
    // Iterate list till it reaches last node
    while(currNode->next != NULL){
        currNode->data = currNode->next->data;

        prev = currNode;
        currNode = currNode->next;
    }
    delete currNode; // Delete last node 
    prev->next = NULL; // Set prev as last node

    return true;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data : Test Case 1
    node* head = createNode(30);
    head->next = createNode(20);
    head->next->next = createNode(21);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(15);

    // Creating, connecting nodes & initializing their data : Test Case 2
    // node* head = createNode(12);
    // head->next = createNode(15);
    // head->next->next = createNode(10);
    // head->next->next->next = createNode(11);
    // head->next->next->next->next = createNode(5);
    // head->next->next->next->next->next = createNode(6);
    // head->next->next->next->next->next->next = createNode(2);
    // head->next->next->next->next->next->next->next = createNode(3);

    // Creating, connecting nodes & initializing their data : Test Case 3
    // node* head = createNode(10);
    // head->next = createNode(21);
    // head->next->next = createNode(25);
    // head->next->next->next = createNode(16);
    // head->next->next->next->next = createNode(50);
    // head->next->next->next->next->next = createNode(26);
    // head->next->next->next->next->next->next = createNode(31);
    // head->next->next->next->next->next->next->next = createNode(10);
    // head->next->next->next->next->next->next->next->next = createNode(12);

    Traversel(head);
    // Function call  
    if(deleteNode_withoutHead1(head->next)){
        Traversel(head);
    }
    else{
        cout<<"List is undefined!";
    }

    return 0;
}