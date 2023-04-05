// Program to delete consequtive nodes with zero sum in list ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    long data;
    struct node* next;
};

// Creates node to list
struct node* createNode(long data){
    struct node* n = new node;
    n->data = data;
    n->next = NULL; 
    return n;
}

// Displays list elements
void Traversel(struct node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Deletes subList with zero sum ~ O(n) & O(n)
struct node* deleteConsequtiveNodes_withZeroSum(struct node* head){
    // Edge case
    if(!head || !head->next)
        return head;
        
        struct node* dummyNode = createNode(0); // Creating dummynode in case head gets deleted
        dummyNode->next = head;

        unordered_map<int,struct node*> uMap; // Creating Map
        uMap[0] = dummyNode; // Store dummynode with key 0 in map
        long pSum = 0;
        
        // Iterate list till end
        while(head != NULL){
            pSum += head->data;
            
            // If key with node found in map
            if(uMap.find(pSum)!=uMap.end()){
                struct node* prev = uMap[pSum];
                struct node* start = prev;
                
                // Delete nodes with zerosum
                long prefix = pSum;
                while(prev != head){
                    prev = prev->next;
                    prefix += prev->data;
                    if(prev != head) uMap.erase(prefix);
                }

                start->next = head->next;
            }else{
                uMap[pSum]= head;
            }
            // Move to each node
            head = head->next;
        }  
    return dummyNode->next;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(-3);
    head->next->next->next->next = createNode(4);
    Traversel(head);

    // Function call
    head = deleteConsequtiveNodes_withZeroSum(head);
    Traversel(head);
    return 0;
}