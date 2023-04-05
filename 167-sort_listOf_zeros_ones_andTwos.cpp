// Program to sort list of 0s 1s & 2s ~ O(n) & O(1) | Constant space is used as the new three list created are not depending on the input size(n) of original list that means the created list have lesser number of nodes than the original one, thats why its Constant. But you differ the size of those new list as let say k, l, m respectively then the space complexity has to be mentioned which will be O(k+l+m) --> But actually this sizes are lesser hence we can assume the variables k, l, m as n hence overall space will be O(n) but this time we get lesser nodes than the original one(does not depending on the input size(n) of original list) hence this space complexity is constant.
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
};

// Creates node & sets its data
struct node* createNode(int data){
    struct node* n = new node;
        n->data = data;
        n->next = NULL;
    return n;
}

// Sorts list by changing links
struct node* sortList(struct node* head){
    // Check if list is empty or single noded
    if(!head || !head->next){
        return head;
    }
    // Create three dummy nodes
    struct node* zerod = createNode(0); struct node* oned = createNode(0); struct node* twod = createNode(0);
    
    // Store the dummy nodes
    struct node* zero = zerod; struct node* one = oned; struct node* two = twod;

    struct node* curr = head;
        // Traverse the list
        while(curr != NULL){
            if(curr->data == 0){
                zero->next = curr;
                zero = zero->next;
            }
            else if(curr->data == 1){
                one->next = curr;
                one = one->next;
            }
            else if(curr->data == 2){
                two->next = curr;
                two = two->next;
            }
            else{
                cout<<"list data different";
                return NULL;
            }
            curr = curr->next;
        }
        // Connect this three lists by together
        zero->next = (oned->next) ? oned->next : twod->next; // When node with ones are not in the list 
        one->next = twod->next;
        two->next = NULL;

        // Update head
        head = zerod->next;

        // Delete dummy nodes
        delete zerod; delete oned; delete twod;
   
    return head;
}

// Traverses each node
void traversel(struct node* head){
    struct node* p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

// Driver code
int main(){
    // Creating nodes & allocating memory dynamically
    struct node* head = new node;
    struct node* second = new node;
    struct node* third = new node;
    struct node* fourth = new node;

    // Connecting the nodes & initializing their data
    head->data = 2;
    head->next = second;
    
    second->data = 0;
    second->next = third;

    third->data = 1;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = NULL;

    // Functions call
    traversel(head);
    cout<<endl;
    head = sortList(head);
    traversel(head);
    return 0;
}