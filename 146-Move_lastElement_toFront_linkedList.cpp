#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void traversel(node* head){
    node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

node* lastTofirst(node* head){
    node* ptr = head;
    node* tmp = NULL;

    while(ptr->next != NULL){
        tmp = ptr;
        ptr = ptr->next; 
    }
    tmp->next = NULL;   
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){
    node *head = (node*)malloc(sizeof(node));
    node *second = (node*)malloc(sizeof(node));
    node *third = (node*)malloc(sizeof(node));
    node *fourth = (node*)malloc(sizeof(node));

    head->data = 12;
    head->next = second;
    second->data = 34;
    second->next = third;
    third->data = 48;
    third->next = fourth;
    fourth->data = 50;
    fourth->next = NULL;

    traversel(head);
    cout<<endl;
    head = lastTofirst(head);
    traversel(head);
    return 0;
}