// Program to add lists ~ O(l1+l2) & O(1) ~ `Two Approaches 'coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic template
struct node{
    int data;
    node* next;
};

// Creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to sum lists
void sumLists(node* head1, node* head2){
    // Edge case
    if(head1 == NULL || head2 == NULL){
        cout<<"list is empty";
        return;
    }

    long num1 = 0; long num2 = 0;
    long sum = 0;
        // Iterate till end
        while(head1 != NULL && head2 != NULL){
            num1 = (num1*10) + head1->data;
            num2 = (num2*10) + head2->data;
            
            head1 = head1->next;
            head2 = head2->next;
        }
    sum = num1 + num2;
    cout<<"List 1 : "<<num1<<"   "<<"List 2 : "<<num2<<endl;
    cout<<"Sum Is : "<<sum;
}

// Function to concate node's data to string
string dataTostring(node *head){
    node *p = head;
    
    string newNum;
    while(p != NULL){
        newNum += to_string(p->data); 
        p = p->next;
    } 
    return newNum;
}

// Driver code
int main(){
    // List 1
    node* head1 = createNode(8);
    head1->next = createNode(4);
    head1->next->next = createNode(6);
    head1->next->next->next = createNode(9);
    head1->next->next->next->next = createNode(4);
    // List 2
    node* head2 = createNode(4);
    head2->next = createNode(8);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(1);
    head2->next->next->next->next = createNode(3);

    // Function call 1
    sumLists(head1, head2);
    cout<<endl;

    // Function call 2
    string num1 = dataTostring(head1);
    string num2 = dataTostring(head2);
    int sum = stoi(num1) + stoi(num2);

    return 0;
}