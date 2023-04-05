// Program to convert given binary list to its decimal value ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    int val;
    node* next;

    node(int val, node* next){
        this->val = val;
        this->next = next;
    }
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

// Method to convert given binary list to its decimal value - O(n) & O(1)
int getDecimalValue(node* head) {
    // Edge case
    if(!head)
        return 0;

    int decimalTillNow = 0;

        // Iterate till end 
        while(head){
            // Build the decimal of till reached current binary node and add to currDecimal so can do the same for next one
            decimalTillNow = (decimalTillNow*2) + head->val;
            head = head->next;
        }
    
    return decimalTillNow;
}

// Driver code
int main(){
    // Creating, connecting nodes and initializing their data 
    node* fourth = new node(1, nullptr);
    node* third = new node(1, fourth);
    node* second = new node(0, third);
    node* head = new node(1, second);
    Traversal(head);

    // Method call
    int decimalValue = getDecimalValue(head);
    cout<<"Decimal is : "<<decimalValue;

    return 0;
}