// Program to perform deletion operations in list ~ coded by vHiren
#include <iostream>
using namespace std;

// Basic Template 
class Node{
public:
    long val;
    Node* next;

    // Parameterized constructor
    Node(long val){
        this->val = val;
        this->next = NULL;
    }    
};

// Template to declare and define list methods
class ListMethod{
public:
    // Methods prototype
    static void Traversel(Node*);
    static long listLength(Node*);
    static Node* deleteAtHead(Node*);
    static Node* deleteAtTail(Node*);
    static Node* deleteAtMiddle(Node*, long);
    static Node* deleteArbitrary(Node*, long, long);
    static Node* freeMemory(Node*);
};

// Prints list ~ O(n) & O(1) | Uses constant space due to tail recursion
void ListMethod::Traversel(Node* head){
    if(!head) 
        return;
    cout<<head->val<<" ";
    Traversel(head->next);
}

// Method to find length of the list ~ O(n) & O(n)
long ListMethod::listLength(Node* head){
    if(!head) 
        return 0;
    static long len = 0; len++;

    listLength(head->next);
    return len;
}

// #1 - Method to delete node at head of the list ~ O(1) & O(1)
Node* ListMethod::deleteAtHead(Node* head){
    // Edge case
    if(!head){
        return NULL;
    }
    else{
        // Delete and update head
        Node* curr = head;
        head = head->next;
        delete curr;
    }
    return head;
}

// #2 - Method to delete node at tail of the list ~ O(n) & O(1)
Node* ListMethod::deleteAtTail(Node* head){
    // Edge case
    if(!head || !head->next){
        return NULL;
    }
    else{
        Node* nodeTail = head; // To track tail node
        Node* prevTail;
        
        // Iterate and find tail with its previous node
        while(nodeTail->next){
            prevTail = nodeTail;
            nodeTail = nodeTail->next;    
        }
        // Set link and delete tail node
        prevTail->next = nodeTail->next;
        delete nodeTail;
    }
    return head;
}

// #3 - Method to delete node at middle of the list ~ O(n/2) --> O(n) & O(1)
Node* ListMethod::deleteAtMiddle(Node* head, long len){
    // Edge case
    if(!head || !head->next){
        return NULL;
    }
    else{
        Node* nodeMid = head; // To track middle node
        Node* prevMid;
        
        int i=0;
        // Iterate and find middle with its previous node
        while(i != len/2 && nodeMid->next){
            prevMid = nodeMid;
            nodeMid = nodeMid->next;   
            i++; 
        }
        // Set link and delete middle node
        prevMid->next = nodeMid->next;
        delete nodeMid;
    }
    return head;
}

// #4 - Method to delete node at random position in list ~ O(pos-1) = O(pos) --> O(n) & O(1)
Node* ListMethod::deleteArbitrary(Node* head, long pos, long len){
    // Edge case
    if(!head || pos<=0 || pos>len){
        return NULL;
    }
    else if(pos==1){
        head = deleteAtHead(head);
    }
    else{
        Node* nodePos = head; // To track position node
        Node* prevNode;
        
        int i=0;
        // Iterate and find position node with its previous node
        while(i != pos-1 && nodePos){
            prevNode = nodePos;
            nodePos = nodePos->next;   
            i++; 
        }
        // Set link and delete position node
        prevNode->next = nodePos->next;
        delete nodePos;
    }
    return head;
}

// Method to delete list ~ O(n) & O(1)
Node* ListMethod::freeMemory(Node* head){
    Node* currNode = head; Node* nextNode;

    // Iterate list and delete each node
    while(currNode){
        nextNode = currNode->next; 
        delete currNode; 
        currNode = nextNode;
    }
    head = NULL; // After deletion set list as empty 
    return head;
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    ListMethod::Traversel(head);

    // Method call
    long len = ListMethod::listLength(head);

    // #1 Method call
    // head = ListMethod::deleteAtHead(head); cout<<endl;

    // #2 Method call
    // head = ListMethod::deleteAtTail(head); cout<<endl;

    // #3 Method call
    // head = ListMethod::deleteAtMiddle(head, len); cout<<endl;

    // #4 Method call
    // head = ListMethod::deleteArbitrary(head, 2, len); cout<<endl;

    // Method call
    head = ListMethod::freeMemory(head); cout<<endl;
    ListMethod::Traversel(head);

    return 0;
}