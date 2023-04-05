// Program to segregate circular list in two halves ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
};

static int listCount=0;
// Function to segregate circular list in two halves
void splitList(struct node* head){
    struct node* q = head;
    int i=1;

        // When total nodes are even in list 
        if(listCount%2 == 0){
            // Prints the first half
            while(i<=listCount/2){
                cout<<q->data<<" ";
                q = q->next;
                i++;
            }
            cout<<endl;
        }
        // When total nodes are odd in list
        else{
            // Prints the first half
            while(i<=(listCount/2)+1){
                cout<<q->data<<" ";
                q = q->next; 
                i++;
            }
            cout<<endl;
        }
        // Store q's next to p to segregate second half from first half
        struct node* p = q->next;
        
        cout<<q->data<<" ";
        // Set the first halve 
        q->next = NULL;

    // Prints the second half
    do{
        cout<<p->data<<" "; p = p->next;
    }while(p != head);
}

// Driver code
int main(){
    // Creating nodes
    struct node* head = new node;
    struct node* second = new node;
    struct node* third = new node;
    struct node* fourth = new node;
    struct node* fifth = new node;
    struct node* sixth = new node;
    struct node* seventh = new node;

    // Connecting the nodes & initializing their data
    head->data = 1;
    head->next = second;
    listCount++;

    second->data = 2;
    second->next = third;
    listCount++;

    third->data = 3;
    third->next = fourth;
    listCount++;

    fourth->data = 4;
    fourth->next = fifth;
    listCount++;

    fifth->data = 5;
    fifth->next = sixth;
    listCount++;
    
    sixth->data = 6;
    sixth->next = seventh;
    listCount++;
    
    seventh->data = 7;
    seventh->next = head;
    listCount++;

    // Function call
    splitList(head);
    return 0;
}