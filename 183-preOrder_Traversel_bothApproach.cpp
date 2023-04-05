// Program to find Preorder Traversel using iterative and recursive approach
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

// #1 Preorder traversel ~ Recursive 
void preOrderR(struct node* root){
    struct node *p = root;
    if(root != NULL){
        cout<<p->data<<" ";
        preOrderR(p->left);
        preOrderR(p->right);
    }
    return;
}

// #2 Preorder traversel ~ Iterative 
void preOrderI(struct node* root){
    // Base condition
    if(root == NULL){
        return;
    }
    // Using 1-stack
    stack<struct node*> st;
    st.push(root);

        while(!st.empty()){
            // Initialize current to stack's topMost
            struct node* curr = st.top();
            cout<<curr->data<<" ";
            st.pop();

            // Here curr->rigt bcz, while cout - stack's topmost which will be leftNode will get printed
                if(curr->right != NULL){
                    st.push(curr->right);
                }
                if(curr->left != NULL){
                    st.push(curr->left);
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

    // Preorder traversels
    preOrderR(root);
    cout<<endl;
    preOrderI(root);
    return 0;
}