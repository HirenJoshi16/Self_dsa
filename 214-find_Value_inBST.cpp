// Program To Search Given Key In A BST
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

// Finds given value in BST ~ Recursive way
struct node* findinBSTR(struct node* root, int key){
    // If tree is empty or key found at root
    if(root == NULL || root->data == key){
        return root;
    }
    // If key is greater than root
    if(root->data < key){
        return findinBSTR(root->right, key);
    }
    // If key is lesser than root
    return findinBSTR(root->left, key);
}

// Finds given value in BST ~ Iterative way
struct node* findinBSTI(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    else{
        while(root != NULL){
            if(root->data == key){
                return root;
            }
            else if(root->data > key){
                root = root->left;
            }
            else{
                root = root->right;
            }
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

    struct node* n = findinBSTI(root, 5);
    if(n!=NULL){
        cout<<"value found : "<<n->data;
    }
    else{
        cout<<"value not found";
    }
    return 0;
}