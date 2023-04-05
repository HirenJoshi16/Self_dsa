#include <bits/stdc++.h>
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

// Finds minimum value to BST ~ recursive way
struct node* findMinR(struct node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL){
        return root;
    }
    findMinR(root->left);
}

// Finds minimum value to BST ~ iterative way
struct node* findMinI(struct node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Finds maximum value to BST ~ recursive way
struct node* findMaxR(struct node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL){
        return root;
    }
    findMaxR(root->right);
}

// Finds maximum value to BST ~ iterative way
struct node* findMaxI(struct node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

// Driver code
int main(){
    // Creating nodes
    struct node* root = createNode(20);
    struct node* p1 = createNode(8);
    struct node* p2 = createNode(22);
    struct node* p3 = createNode(4);
    struct node* p4 = createNode(12);
    struct node* p5 = createNode(10);
    struct node* p6 = createNode(14);
    // Setting the root node
    root->left = p1;
    root->right = p2;

    // Setting the left nodes
    p1->left = p3;
    p1->right = p4;
    p4->left = p5;
    p4->right = p6;

    preOrderI(root);
    cout<<endl;
    struct node* n = findMaxI(root);
    if(n != NULL){
        cout<<"Maximum : "<<n->data;
    }
    else{
        cout<<"No maximum";
    }
    return 0;
}