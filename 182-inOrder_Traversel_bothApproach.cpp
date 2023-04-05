// Program to find Inorder Traversel using iterative and recursive approach
#include <iostream>
#include <malloc.h>
#include <stack>

using namespace std;

// Basic Template
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Creates node and initializes their data
struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

// #1 Inorder traversel ~ Recursive 
void inOrderR(struct node* root){
    struct node *p = root;
    if(root != NULL){
        inOrderR(p->left);
        cout<<p->data<<" ";
        inOrderR(p->right);
    }
    return;
}

// #2 Inorder traversel ~ Iterative 
void inOrderI(struct node* root){
    // Base condition
    if(root == NULL){
        return;
    }
    // Using 1-stack
    stack<struct node*> st;
    struct node *curr = root;
        
        while(curr!=NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                curr = st.top();
                st.pop();
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
}

// Driver code
int main(){
    // Creating nodes
    struct node* root = createNode(9);
    struct node* p1 = createNode(4);
    struct node* p2 = createNode(15);
    struct node* p3 = createNode(1);
    struct node* p4 = createNode(5);
    struct node* p5 = createNode(20);

    // Setting the root node
    root->left = p1;
    root->right = p2;

    // Setting the left nodes
    p1->left = p3;
    p1->right = p4;

    // Setting the right nodes
    p2->right = p5;

    // Inorder traversels
    inOrderR(root);
    cout<<endl;
    inOrderI(root);
    return 0;
}