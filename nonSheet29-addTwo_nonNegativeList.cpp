// Program to add two non negative list ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    int data;
    node* next;
};

// Creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = nullptr;
}

// Prints list elements
void Traversel(node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"   ";
}

// Function to add two list - O(n) & O(n)
node* addTwoList(node* head1, node* head2){
    // Edge case
    if(!head1 || !head2) return nullptr;

    node* dummynode = createNode(0);
    node* tmp = dummynode;

    int sum = 0;
    int carry = 0;

    // Iterate both list till end
    while(head1 || head2 || carry){
        int sum = 0;
        if(head1){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2){
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry; // Update sum if there is a carry spawned previously
        carry = sum/10; // Update carry each time
        
        // Populate new list 
        node* newNode = createNode(sum%10);
        tmp->next = newNode;
        tmp = tmp->next;
    }
    node* sumHead = dummynode->next;
    delete dummynode; // Delete else memory leak problem can occur

    return sumHead;
}

// Function to delete list
void freeMemory(node** head){
    node* currNode = *head; node* next;

    // Iterate list and delete each node
    while(currNode){
        next = currNode->next; 
        delete currNode; 
        currNode = next;
    }
    *head = nullptr; // After deletion set list as empty 
}

// Driver code
int main(){
    // List 1 : Creating, connecting nodes & initializing their data
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(1);

    // List 2 : Creating, connecting nodes & initializing their data
    node* second = createNode(4);
    second->next = createNode(5);
    second->next->next = createNode(6);

    // Traversel call
    Traversel(head); Traversel(second);
    cout<<endl;

    // Function call
    node* sumHead = addTwoList(head, second);
    if(sumHead != nullptr){
        Traversel(sumHead);
    }
    else{
        cout<<"List undefined!"; 
    }

    // Deallocating memory
    freeMemory(&head); freeMemory(&second);
    return 0;
}