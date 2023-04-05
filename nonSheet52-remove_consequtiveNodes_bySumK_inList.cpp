// Program to delete consecutive nodes by given sum ~ coded by vHiren
#include <iostream>
#include <unordered_map>
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

// Method to remove consecutive nodes by given sum - O(n) & O(n)
node* removeConseqNodes_sumsK(node* head, int k){
    // Edge case
    if(!head)
        return nullptr;

    // When list contain single node equals k
    if(!head->next && head->val == k)
        return head->next;

    node* dummynode = new node(0, head); // Required to handle cases when head gets removed

    unordered_map<int, node*> hashMap;
    hashMap[0] = dummynode; // To handle cases when head or node equals k has to removed

    long sum = 0;

        // Iterate till end
        while(head){
            sum += head->val;
        
            // If present then we found the previous/starting point from where the consecutive nodes will exist that sums to k till current node
            if(hashMap.count(sum-k)){
                node* tmp = (hashMap[sum-k]);
                tmp->next = head->next; // Set link correctly
                
                // Never erase entry of (0, dummy) because it will always in need, when the head gets deleted or the sublist for removal may start from head node or when the current node is equal to k then we absolutely want to remove it. Whenever for a node if sum-k becomes 0 hence we want that 0 to be in the map else we cant remove the node
                if(sum-k != 0)
                    hashMap.erase(sum-k);
                
                head = tmp->next;
                sum = 0; // Reset sum to 0
            }
            // Else store because it is possible that current node can be a starting point of consecutive node for later
            else{
                hashMap[sum] = head;
                head = head->next;
            }
        }
        head = dummynode->next; // Update new head

        dummynode->next = nullptr; // Set dummynode for deletion else it means that the memory for the original node is lost and can not be freed correctly 
        delete dummynode; // Delete to avoid memory leak problems

    return head;
}

// Driver code
int main(){
    // Creating, connecting nodes and initializing their data
    node* fifth = new node(5, nullptr); 
    node* fourth = new node(4, fifth);
    node* third = new node(3, fourth);
    node* second = new node(2, third);
    node* head = new node(1, second);
    Traversal(head);

    // Method call
    head = removeConseqNodes_sumsK(head, 3);
    Traversal(head);

    return 0;
}