// Program to find Triplets in Dll equal to given sum ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    node* prev;
    int data;
    node* next;
};

// Creates node & initializes its data
node* createNode(int data){
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
}

// Function to find Triplets to given sum
bool findTriplets(node* head, int sum){
    // Edge case
    if(!head || !head->next){
        return false;
    }
    
    // Create three pointers
    node* prevv = head;
    node* curr = head->next;
    node* nextt = head->next->next;

    // Print Triplets if found at beginning
    if(prevv->data + curr->data + nextt->data == sum){
        cout<<prevv->data<<" "<<curr->data<<" "<<nextt->data;
    }
    else{
        // Iterate from second node till end
        while(curr->next != NULL){
            if(prevv->data + curr->data + nextt->data == sum){
                cout<<prevv->data<<" "<<curr->data<<" "<<nextt->data;
                break;
            }
            prevv = prevv->next;
            curr = curr->next;
            nextt = nextt->next;
        }
    }
    return true;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(2);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(6);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(8);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = createNode(1);
    head->next->next->next->next->next->prev = head->next->next->next->next;        
    Traversel(head);
    cout<<endl;

    int sum = 15;
    // Function call
    if(findTriplets(head, sum)){
        cout<<"\nTriplets found!";
    }
    else{
        cout<<"No Triplets with given sum!";
    }

    return 0;
}