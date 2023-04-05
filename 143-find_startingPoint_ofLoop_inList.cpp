// Program to find the node where cycle begins ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    int val;
    node* next;

    node(int val) : val(val), next(nullptr) {}
    node(int val, node* next) : val(val), next(next) {}

    // Deletes list recursively and deallocates resources memory allocated using new keyword
    ~node(){
        if(next)
            delete next;
    }
};      

// Method to print list
void Traversal(node* head){
    if(!head){
        cout<<endl;
        return;
    }
    cout<<head->val<<" ";
    Traversal(head->next);
}

// Method to find node where cycle begins - O(n) & O(1)
node* detectCycleNode(node *head) {
    // Edge case
    if(!head || head->next == head) return head;

    node* slow = head; node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;

            while(slow != fast)
                slow = slow->next, fast = fast->next;   
            return slow;
        }
    }
    
    return nullptr;
}  

// Driver code
int main(){
    // Creating, connecting nodes and initializing their data
    node* head = new node(10, new node(20, new node(30, new node(40, nullptr))));
    Traversal(head);

    // Setting up list cycle
    node* tmp = head->next->next->next;
    tmp->next = head->next;
    cout<<"Tail connects to node at position : 2"<<endl;

    // Method call
    cout<<"Cycle begins at : "<<(detectCycleNode(head))->val;

    return 0;
}