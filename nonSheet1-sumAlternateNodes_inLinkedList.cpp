// Program to sum alternate nodes to list ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    long data;
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
node* createNode(long data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// #1 - Adds alternative nodes to list ~ O(n) & O(1)
void sumAlternateNodes(node* head, long& sum){
    // Edge case
    if(!head || !head->next)
        return;
    bool isOdd = true;

    // Iterate list till end
    while(head != NULL){
        // Adding alternate node
        if(isOdd)
            sum += head->data; 
        isOdd = !isOdd;
        head = head->next;
    }
}

// #2 - Adds alternative nodes to list ~ O(n) & O(1)
void sumAlternateNodes_Recursive(node* head, long& sum, bool isOdd = true){
    // Edge case
    if(!head)
        return;
    // Adding alternative node
    if(isOdd == true)
        sum += head->data;
        
    sumAlternateNodes_Recursive(head->next, sum, !isOdd);
}
// It seems O(n) extra space due to recursion call stack but here function is the tail recursive function and thus the compilers optimize it to use constant extra space

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data : Test Case 1
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    Traversel(head);
    long sum = 0;
    // Function call  
    sumAlternateNodes(head, sum);
    cout<<sum;
    
    return 0;
}