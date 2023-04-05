// Program to merge two sorted lists ~ coded by vHiren
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

// Method to merge two sorted lists - O(n) & O(1)
node* mergeTwoLists(node* list1, node* list2) {
    // Edge cases
    if(!list1 && !list2) return nullptr;
    if(!list1 && list2->next) return list2;
    if(!list2 && list1->next) return list1;

    node* newList = new node(0); // Stores result list
    node* newListCurrent = newList;

    node* first = list1; // Tracks list1
    node* second = list2; // Tracks list2

        while(first && second){
            // Compare and set nodes correctly
            if(first->val < second->val){
                execute_If_Block: // Needed when Else Block is executed 

                newListCurrent->next = first;
                newListCurrent = newListCurrent->next;
                first = first->next; // Move to next node in list1
            }
            else if(first->val > second->val){
                execute_ElseIf_Block: // Needed when Else Block is executed 

                newListCurrent->next = second;
                newListCurrent = newListCurrent->next;
                second = second->next; // Move to next node in list2
            }
            else{
                // Do the same thing we have done in If Block
                goto execute_If_Block;
                
                // Then do the same thing we have done in Else-If Block
                goto execute_ElseIf_Block;
            }
        }
        
        if(!first)
            newListCurrent->next = second; // Do when nodes of list2 are left
        else
            newListCurrent->next = first; // Else do when nodes of list1 are left

    node* newHead = newList->next; // Set the head of new list
    newList->next = nullptr; // Break its link to safely delete it without losing memory of its next node
    delete newList; // Delete to avoid memory leak problems

    return newHead;
}

// Driver code
int main(){
    // List 1
    node* list1 = new node(1, new node(2, new node(3, nullptr)));
    Traversal(list1);

    // List 2
    node* list2 = new node(1, new node(1, new node(4, nullptr)));
    Traversal(list2);

    // Method call
    node* newHead = mergeTwoLists(list1, list2);
    Traversal(newHead);
    
    return 0;
}