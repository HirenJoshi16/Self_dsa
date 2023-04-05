// Program to insert node in a BST - coded by vHiren 
#include <iostream>
#include <malloc.h>
using namespace std;

// Basic Template
struct node {
    int data;
    node* left;
    node* right;
};

// Creates node and initializes their data
node* createNode(int data) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}
 
// Method to print tree 
void inOrder(node* root) {
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

// Method to insert node in a BST - O(N) & O(1)
node* insertIntoBST(node* root, int key) {
    if(!root)
        return createNode(key);

    node* curr = root;
    while(curr){
        // When root is lesser
        if(curr->data < key) {
            if(curr->right)
                curr = curr->right;
            else {   
                curr->right = createNode(key);
                break;
            }
        }
        // When root is greater
        else {
            if(curr->left)
                curr = curr->left;
            else {
                curr->left = createNode(key);
                break;
            }    
        }
    }
    
    return root;
}

// Driver code
int main() {
    // Creating nodes
    node* root = createNode(9);
    node* p1 = createNode(4);
    node* p2 = createNode(15);
    node* p3 = createNode(1);
    node* p4 = createNode(5);
    node* p5 = createNode(20);

    // Setting the root node
    root->left = p1;
    root->right = p2;

    // Setting the left nodes
    p1->left = p3;
    p1->right = p4;

    // Setting the right nodes
    p2->right = p5;
    inOrder(root); cout<<endl;

    int key = 8;
    // Method call
    root = insertIntoBST(root, key);
    inOrder(root);
    
    return 0;
}