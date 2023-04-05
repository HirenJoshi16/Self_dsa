// Program to add 1 to number represented by list
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node
{
    int data;
    struct node *next;
};

// Traverses each element
void traversel(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// Creates node & initializes its data
struct node *createNode(int data)
{
    struct node *n = new node;

    n->data = data;
    n->next = NULL;
    return n;
}
//

// Reverses list
struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nextPtr;

    while (curr != NULL)
    {
        nextPtr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextPtr;
    }
    return prev;
}

// adds 1 to number represented by list
struct node* addOnetoList(struct node* head){
    // Edge case
    if(head == NULL || head->next ==  NULL){
        return head;
    }
    // Set three pointers by reversing actual list
    struct node* prev = NULL;
    struct node* curr = reverse(head);
    struct node* newHead = curr;
    
    int carry = 0;
        // Iterate list
        while(curr != NULL){
            int sum = 0;
            // In case if current is at head node
            if(prev == NULL){
                sum = curr->data + 1;
            }
            else{
                sum = curr->data + carry;
            }
            // Update or set carry & sum at each node
            carry = sum/10;
            curr->data = sum%10;
            prev = curr;
            curr = curr->next;
        }
    // If total sum is oned
    if(carry == 1){
        node* n = createNode(carry);
        prev->next = n;
        prev = n;
    }
    return reverse(newHead);
}

// Driver code
int main()
{
    // Creating, connecting nodes & initializing their data
    struct node *head = createNode(1);
    head->next = createNode(9);
    head->next->next = createNode(9);
    head->next->next->next = createNode(9);
    head->next->next->next->next = createNode(9);
    traversel(head);
    cout<<endl;

    // Function call
    head = addOnetoList(head);
    traversel(head);
    return 0;
}