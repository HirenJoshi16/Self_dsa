// Program to perform deletion in a BST ~ coded by Hiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int val;
    struct node* left;
    struct node* right;
};

// Method to create node and initialize its data
struct node* createNode(int val){
    struct node* n = new node();
    n->val = val;
    n->left = nullptr;
    n->right = nullptr;
}

// Method to print tree 
void inOrder(struct node* root){
    struct node *p = root;
    if(root != nullptr){
        inOrder(p->left);
        cout<<p->val<<" ";
        inOrder(p->right);
    }
    return;
}

// Finds inorder successor of given node
struct node* inOrderSuccessor(struct node* root){
    // Successor of given root is always at the right subtree's leftmost node
    root = root->right;
    while(root->left)
        root = root->left;

    return root;
}

// Method to delete a node in a BST - O(H) & O(H)
struct node* deleteNode(struct node* root, int key){
    if(!root){
        return root;
    }
    // Search for the node
    if(key < root->val){
            root->left = deleteNode(root->left, key);
    }
    else if(key > root->val){
        root->right = deleteNode(root->right, key);
    }
    // Perform deletion action when the node is found
    else{
        // If left child is null then return right child, In case both are null then it will return right child(null)
        if(!root->left){
            struct node* tmp = root->right;
            delete root;
        }
        // If left is not null and right is null then it will return right child
        else if(!root->right){
            struct node* tmp = root->left;
            delete root;
            return tmp;
        }
        // When current node has two child than find inorder successor and replace it with node and delete inorder successor
        else{
            // Find the inorder successor of current node
            struct node* iSuccessorNode = inOrderSuccessor(root);
            // Copy its data to current node
            root->val = iSuccessorNode->val;
            // Find and delete the successor node, As we know successor is always found on right side thus : root->right
            root->right = deleteNode(root->right, iSuccessorNode->val);
        }
    }
    return root;
}

// Driver code
int main(){
    // Creating nodes
    struct node* root = createNode(5);
    struct node* p1 = createNode(3);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(1);
    struct node* p4 = createNode(4);

    // Setting the root node
    root->left = p1;
    root->right = p2;

    // Setting the left nodes
    p1->left = p3;
    p1->right = p4;

    inOrder(root); cout<<endl;
    // Method call
    root = deleteNode(root, 3);
    inOrder(root);
    
    return 0;
}