// Program to check linked list a palindrome or not ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    int val;
    node* next;

    node(int val){
        this->val = val;
        this->next = nullptr;
    }
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

// Method to check list is palindrome or not - O(n) & O(1)
bool isPalindrome(node* head){
    // Edge case : When list is empty
    if(!head->next) return true;
    
    // Edge case : When two nodes exist such their values are not same
    if(!head->next->next && head->val != head->next->val) 
        return false;

    node* slow = head; node* curr = head;
        // Find middle node
        while(curr && curr->next)
            slow = slow->next, curr = curr->next->next;

    node* tmp = slow->next; // Needed for reversel
    slow->next = nullptr; // Break first half

    curr = slow; node* next;
        // Iterate and reverse second half 
        while(tmp)
            next = tmp->next, tmp->next = curr, curr = tmp, tmp = next;

    slow = head;
        // Iterate from both the ends 
        while(curr){
            // If values are not equal
            if(curr->val != slow->val)
                return false;

            curr = curr->next; // Move in first half
            slow = slow->next; // Move in second half
        }

    return true;
}

// Driver code
int main(){
    // Creating, connecting nodes and initializing their data
    node* head = new node(1, new node(2, new node(3, new node(2, new node(1, nullptr)))));
    Traversal(head);

    // Method call
    if(isPalindrome(head))
        cout<<"List is palindrome";
    else
        cout<<"List is not palindrome";

    return 0;
}