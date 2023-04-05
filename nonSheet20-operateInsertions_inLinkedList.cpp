// Program to perform insertion operations in list ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    long val;
    node* next;
};

// Function that creates node & initializes its data ~ O(1) & O(1)
node* createNode(long val){
    node* newNode = new node;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Prints list ~ O(n) & O(1) | Uses constant space due to tail recursion
void Traversel(node* head){
    if(!head) 
        return;
    cout<<head->val<<" ";
    Traversel(head->next);
}

// Function to find length of the list ~ O(n) & O(n)
long listLength(node* head){
    if(!head) 
        return 0;
    static long len = 0; len++;

    listLength(head->next);
    return len;
}

// #1 - Function to insert node at head of the list ~ O(1) & O(1)
node* insertAtHead(node* head, long val){
    node* newNode = new node;
    
    // In case list is empty or memory allocation failed ~ node creation failed
    if(!head || !newNode){
        return NULL;
    }   
    else{
        // Set link & data for new node
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }
    return newNode;
}

// #2 - Function to insert node at tail of the list ~ O(n) & O(1)
node* insertAtTail(node* head, long val){
    node* newNode = new node;
    
    // In case list is empty or memory allocation failed ~ node creation failed
    if(!head || !newNode){
        return NULL;
    }     
    else{
        node* nodeTail = head; // To track last node
        // Iterate list to find last node
        while(nodeTail->next) nodeTail = nodeTail->next;

        // Set link & data for new last node
        newNode->val = val; 
        nodeTail->next = newNode; 
        newNode->next = NULL;
    }
    return head;
}

// #3 - Function to insert node at middle of the list ~ O(n/2) --> O(n) & O(1)
node* insertAtMiddle(node* head, long len, long val){
    node* newNode = new node;
    
    // In case list is empty or memory allocation failed ~ node creation failed
    if(!head || !newNode){
        return NULL;
    }     
    else{
        node* nodeMid = head; // To track middle node
        int i = 0;

        // Iterate list to find middle node
        while(i != len/2 && nodeMid){
            nodeMid = nodeMid->next;
            i++;
        }
        // Set link & data for new node
        newNode->val = val; 
        newNode->next = nodeMid->next;
        nodeMid->next = newNode; 
    }
    return head;
}

// #4 - Function to insert node at random position in list ~ O(pos-1) = O(pos) --> O(n) & O(1)
node* insertArbitrary(node* head, long len, long pos, long val){
    node* newNode = new node;

    // In case list is empty or memory allocation failed or invalid position
    if(!head || !newNode || pos<=0 || pos>len+1){
        return NULL;
    }  
    else if(pos==1){
        head = insertAtHead(head, val);
    }  
    else{
        node* nodePos = head; // To track position node
        int i = 1;

        // Iterate list to find position node
        while(i != pos-1 && nodePos){
            nodePos = nodePos->next;
            i++;
        }
        // Set link & data for new node
        newNode->val = val; 
        newNode->next = nodePos->next;
        nodePos->next = newNode; 
    }
    return head;
}

// Function to delete list ~ O(n) & O(1)
node* freeMemory(node* head){
    node* currNode = head; node* next;

    // Iterate list and delete each node
    while(currNode){
        next = currNode->next; 
        delete currNode; 
        currNode = next;
    }
    head = NULL; // After deletion set list as empty 
    return head;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    Traversel(head); cout<<endl<<endl;

    // Function call
    long len = listLength(head);

    // #1 Function call 
    // head = insertAtHead(head, 0);
    // Traversel(head); cout<<endl;

    // #2 Function call 
    // head = insertAtTail(head, 7);
    // Traversel(head); cout<<endl;

    // #3 Function call 
    // head = insertAtMiddle(head, len, 10);
    // Traversel(head); cout<<endl;

    // #4 Function call 
    // head = insertArbitrary(head, len, 3, 50);
    // Traversel(head); cout<<endl;

    // Function call
    head = freeMemory(head);
    Traversel(head);

    return 0;
}