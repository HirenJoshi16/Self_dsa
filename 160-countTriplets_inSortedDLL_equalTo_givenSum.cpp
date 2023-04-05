// Program to count triplets in sorted DLL equal to given sum ~ coded by vHiren 
#include <iostream>
#include <unordered_map>
using namespace std;

// Basic Template
struct node{
    long data;
    node* prev;
    node* next;
};

// Displays elements to list
void Traversel(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Function that creates node & initializes its data
node* createNode(long data){
    node* n = new node;
    n->prev = NULL;
    n->data = data;
    n->next = NULL;
}

// Function to count all triplets equal to given sum ~ O(n*n) & O(n)
int countTriplets(node* head, long sum){
    // Edge case
    if(!head || !head->next){
        return 0;
    }
    // Creating uMap for <node data, node ptr> 
    unordered_map<int, node*> uMap;

    node* curr;
    // Insert each node with its data in uMap 
    for(curr = head; curr != nullptr; curr = curr->next) uMap[curr->data] = curr;   

        node* ptr1; node* ptr2;

        int count = 0;
        // Iterate list & generate all possible pairs
        for(ptr1 = head; ptr1 != nullptr; ptr1 = ptr1->next){
            for(ptr2 = ptr1->next; ptr2 != nullptr; ptr2 = ptr2->next){
                int currentSum = ptr1->data + ptr2->data;
                
                // if currentSum is present in uMap and uMap[sum-currentSum] node is not equal to one or both of the nodes
                if(uMap.find(sum-currentSum) != uMap.end() && uMap[sum-currentSum] != ptr1 && uMap[sum-currentSum] != ptr2){
                    count++; // Hence increment count
                }
            }
        }
    // Divide by 3 as each triplet is counted 3 times 
    return count/3;
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

    long sum = 12;
    // Function call
    cout<<countTriplets(head, sum);

    return 0;
}