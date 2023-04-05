// Program to reverese list in group of given size ~ coded by vHiren
#include <bits/stdc++.h>
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

// #1 - Function to reverse list in group by given size ~ O(n) & O(n/k) | (n/k)+1 calls will made during recursion
node* reverseList_inGroupR(node* head, long k){
    // Edge case
    if(!head || !head->next || k<=0)
        return head;

    // Creating three pointers
    node* curr = head; node* prev = NULL; node* next = NULL;
    long count = 0;

        // Reverse k nodes in list
        while(curr != NULL && count < k){
            next = curr->next; curr->next = prev;
            prev = curr; curr = next;
            count++;
        }
        // next ptr is used to track (k+1)th node ~ Used to link with head of last reversed set     
        if(next != NULL)   
            head->next = reverseList_inGroupR(next, k);
    
    // New head of original list
    return prev;
}

// #2 - Function to reverse list in group by given size ~ O(n) & O(k) 
node* reverseList_inGroupI(node* head, long k){
    // Edge case
    if(!head || !head->next || k<=0)
        return head;

    // Creating a stack
    stack<node*> st; 
    node* curr = head; node* prev = NULL; 

    // Iterate list till end
    while(curr != NULL){

        long count = 0;
        // Pushing k nodes to stack
        while(curr != NULL && count < k){
            st.push(curr);
            curr = curr->next;
            count++;
        }
        // Pop elements of stack & set links accordingly
        while(!st.empty()){
            // If NULL it means we are reversing first k set of list 
            if(prev == NULL){
                prev = st.top(); head = prev;
                st.pop();
            }
            else{
                // Linking and updating node
                prev->next = st.top(); prev = prev->next; 
                st.pop();
            }
        }

    }
    prev->next = NULL; // Last node will point to NULL
    return head;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(30);
    head->next = createNode(20);
    head->next->next = createNode(21);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(15);
    head->next->next->next->next->next = createNode(45);
    head->next->next->next->next->next->next = createNode(85);
    head->next->next->next->next->next->next->next = createNode(95);
    Traversel(head);
    
    // Function call  
    head = reverseList_inGroupR(head, 5);
    Traversel(head);

    return 0;
}