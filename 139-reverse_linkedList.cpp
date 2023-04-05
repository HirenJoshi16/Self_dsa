// list reversel by iterative and recursive method
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    node *next;
};

void createList(struct node *head){
    struct node *p = head;
    int i=1, limitSize=5, data;

    while(i <= limitSize){
        struct node *node = (struct node*)malloc(sizeof(struct node));
        if(node == NULL){
            cout<<"node creation failed"<<endl;
        }
                else{
                    cout<<"enter data for "<<i<<" node "<<endl;
                    cin>>data;
                    if(i == 1){
                    head->data = data;  
                }
                    else{
                    node->data = data;
                    p->next = node;
                    p = p->next;
                }
        }
        node->next = NULL;
        i++;
    }
}

void traversel(node *head){
    node *p = head;
    while(p != NULL){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

node* reverse(node *head){
    node *prev = NULL;
    node *current = head;
    node *nextPtr;

    while(current!=NULL){
        nextPtr = current->next;
        current->next = prev;

        prev = current;
        current = nextPtr;
    }
    return prev;
}
//Reverses list recursively
struct node* reverseRecursive(struct node* head){
    //Base condition - when list is empty or when only a single node
    if(head == NULL || head->next == NULL){
        return head;
    }

    //Auxiliary space ~ O(N), bcz while the recursive calls stack been created
    struct node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    node *head = (struct node*)malloc(sizeof(node));
    head->next = NULL;

    createList(head);
    cout<<endl;
    traversel(head);
    cout<<endl;

    head = reverse(head);
    traversel(head);
    head = reverseRecursive(head);
    traversel(head);
    return 0;
}