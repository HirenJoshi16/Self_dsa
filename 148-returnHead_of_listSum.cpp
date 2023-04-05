// Program to find list sum by creating new list of sum ~ O(n+m) & O(n+m) | coded by vHiren
#include <iostream>
using namespace std;

// Basic Template
struct node{
    int data;
    node* next;
};

// Creates node & initializes its data
node* createNode(int data){
    node* n = new node;
    n->data = data;
    n->next = NULL;
}

// Prints list elements
void Traversel(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"   ";
}

// Function to find sum of lists #2
long findListSum(node* head, node* second){
    long num1=0; long num2=0; long sum=0;

        // Iterate both list & store their values
        while(head != NULL || second != NULL){
            if(second != NULL){
                num2 = (num2*10) + second->data;
                second = second->next;
            }
            num1 = (num1*10) + head->data;
            head = head->next;
        }
        // Calculate total sum
        sum = num1+num2;

    return sum;
}

// Function to add lists #1 - Works for bigger cases
node* addTwoList(node* head, node* second){
    // Edge case
    if((!head || !head->next) || (!second || !second->next)) return head;
    
    // Function call to find lists sum
    long sum = findListSum(head, second);
    
        // Create two variables - To store sum for later use & to find unit
        long tempSum = sum;
        long long unit = 1;
    
        // Iterate - find & store unit
        while(tempSum != 0){
            unit *= 10;
            tempSum /= 10;
        }
        // Setting correct unit value
        unit /= 10;
    
    // Create two pointers to populate new list of sum
    node* dummyHead = createNode(-1);
    node* newHead = dummyHead;

    // Iterating & populating new list
    while(unit != 0){
        newHead->next = createNode(sum/unit%10);
        newHead = newHead->next;
        unit /= 10;
    }
    return dummyHead->next;
}

// Function to delete list
void freeMemory(node** head){
    node* currNode = *head; node* next;

    // Iterate list and delete each node
    while(currNode){
        next = currNode->next; 
        delete currNode; 
        currNode = next;
    }
    *head = NULL; // After deletion set list as empty 
}

// Driver code
int main(){
    // List 1 : Creating, connecting nodes & initializing their data
    node* head = createNode(7);
    head->next = createNode(2);
    head->next->next = createNode(4);
    head->next->next->next = createNode(3);
    
    // List 2 : Creating, connecting nodes & initializing their data
    node* second = createNode(5);
    second->next = createNode(6);
    second->next->next = createNode(4);

    // Traversel call
    Traversel(head); Traversel(second);
    cout<<endl;

    // Function call
    node* sumList_Head = addTwoList(head, second);
    if(sumList_Head != NULL){
        Traversel(sumList_Head);
        cout<<"\nList created successfully!"; 
    }
    else{
        cout<<"List undefined!"; 
    }

    // Deallocating memory
    freeMemory(&head); freeMemory(&second);
    return 0;
}