// Program to merge nodes lying in between zeros in list ~ coded by vHiren
// There are no two consecutive nodes with node->val == 0 | The beginning and end of the linked list have node->val == 0
#include <iostream>
using namespace std;

// Basic Template
struct node{
    int val;
    node* next;
};

// Creates node & initializes its data
node* createNode(int val){
    node* n = new node;
    n->val = val;
    n->next = NULL;
    return n;
}

// Prints list elements
void Traversel(node* head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Method to merge nodes lying in between zeros - O(n) & O(1)
node* mergeNodes(node* head){
    // Edge case
    if(!head || !head->next) 
        return head;

    // Intended to store resultant nodes
    node* newList = createNode(0); 
    node* tmp = newList;

    head = head->next; // Begin from second node
    long sum = 0;

        // Iterate list till end
        while(head){
            // Take cumulative sum when its not zero
            if(head->val != 0){
                sum += head->val;        
            }
            // Else store resultant nodes in new list
            else{
                node* newNode = createNode(sum);
                tmp->next = newNode;
                tmp = tmp->next;
                sum = 0;
            }
            head = head->next; // Move to each node
        }

    head = newList->next; // Update new head
    delete newList; // Delete this node to avoid memory leak problems

    return head;
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
    *head = NULL; // After deletion set list as empty 
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(0);
    head->next = createNode(5);
    head->next->next = createNode(1);
    head->next->next->next = createNode(0);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next->next = createNode(0);
    Traversel(head);

    // Method call
    head = mergeNodes(head);
    Traversel(head);

    // Deallocating memory
    freeMemory(&head);
    return 0;
}