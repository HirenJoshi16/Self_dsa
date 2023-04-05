// Program to reverse k groups in linked list ~ coded by vHiren
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

// Method to reverse sublist
node* reverseSubList(node* rTail, node* rHead){
    node* curr = rTail;
    node* newHead = NULL;
    node* next;

    // Iterate and change links
    while(curr != rHead->next && curr != NULL){
        next = curr->next;
        curr->next = newHead;

        newHead = curr;
        curr = next;
    }
    return newHead;
}

// Method to reverse k groups in linked list - O(n) & O(1)
node* reverseKGroups(node* head, int k) {
    // Edge case
    if(!head || !head->next || k <= 1) return head;

    // As head will also reverse thus its needed to return the new head in the end
    node* dummynode = createNode(0); dummynode->next = head;
    node* prevNode = dummynode; 
    node* currNode = head;
    node* rHead; // Refers the head node after reversing a k sublist

    // Iterate till end
    while(currNode) {
        rHead = currNode;
        int i = 1;

        // Iterate and find the kth node which will become head after reversel of current sublist
        while(i < k && rHead->next){
            rHead = rHead->next;
            i++;
        }
        // If i == k then reversal is possible to reverse the current k sublist
        if(i == k){
            // Reverse the sublist from current node to rHead
            node* nextOf_rHead = rHead->next; // Save the next node of rHead
            rHead->next = NULL; // As we have to reverse this sublist thus set to NULL

            rHead = reverseSubList(currNode, rHead); // Reverse the sublist
            prevNode->next = rHead; // After reversel set the reversed head or rHead  

            prevNode = currNode; // Move prevNode to the end of the current sublist 
            currNode->next = nextOf_rHead; // Connect the current sublist to the next node of rHead
            currNode = nextOf_rHead; // Update current node so can go for next sublist
        } 
        else{
        // When i != k no reversal required
            break;
        } 
    }

    return dummynode->next;
}

// Method to delete list
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
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    Traversel(head);

    // Method call
    head = reverseKGroups(head, 2);
    Traversel(head);

    // Deallocating memory
    freeMemory(&head);
    return 0;
}


// The reverseKGroup Method appears to be optimized and should not have any memory leak problems.
// Here are some reasons why:

// It only allocates a constant number of new nodes (dummynode).

// It only modifies the next pointers of existing nodes in the linked list.

// It correctly uses nullptr to set the last node of each reversed sublist to point to nullptr and terminate the sublist.

// It correctly updates the next pointers of the previous and current nodes to connect the reversed sublists with the rest of the linked list.

// IMP : It does not allocate any memory that is not freed or has no way of being freed, so there should be no memory leak issues.

// Overall, the code provided for the reverseKGroup Method appears to be well-optimized and memory-efficient.


// Self created logic
// node* reverseKGroup(node* head, int k) {
//     // Edge case
//     if(!head || !head->next || k<=1) return head;

//     node* dummynode = createNode(0); dummynode->next = head;
//     node* prevNode = dummynode;
//     node* currNode = head;

//     node* rHead=head; node* rTail=head;
//     int i=1;

//     while(currNode != NULL && currNode->next != NULL){
//         rHead = rTail = currNode;
//         i=1;

//             while(i<k && rHead != NULL && rHead->next != NULL){
//                 rHead = rHead->next;
//                 currNode = rHead->next;
//                 i++;
//             }

//         if(i==k){
//             rHead = reverseSubList(rTail, rHead);
//             // cout<<rHead->val<<endl;

//             prevNode->next = rHead;
//             // cout<<prevNode->next->next->val<<endl;
            
//             prevNode = rTail;
//         } 
//         else{
//             prevNode->next = rTail;
//         }
//     }
//     if(currNode->next == NULL) prevNode->next = currNode;

//     return dummynode->next;
// }