#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void createList(struct node *head){
    struct node *p = head;
    int i=1, limitSize=3, data;

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

void traversel(struct node *head){
    struct node *p = head;
    while(p != NULL){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

string stringNum(struct node *head){
    struct node *p = head;
    string newNum;
    while(p != NULL){
        newNum += to_string(p->data); 
        p = p->next;
    } 
    return newNum;
}

int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    
    cout<<"setting elements for 1st list : "<<endl;
    createList(head);
    cout<<endl;
    cout<<"showing elements of 1st list :"<<endl;
    traversel(head);
    cout<<endl;
    long long a = stoi(stringNum(head));
    cout<<"list elements : "<<a;

    cout<<endl;
    cout<<endl;

    cout<<"setting elements for 2nd list : "<<endl;
    createList(head);
    cout<<endl;
    cout<<"showing elements of 2nd list :"<<endl;
    traversel(head);
    cout<<endl;

    long long b = stoi(stringNum(head));
    cout<<"list elements : "<<b;

    cout<<"\nproduct of list's element is : "<<a<<" * "<<b<<" = "<<a*b;
    return 0;
}