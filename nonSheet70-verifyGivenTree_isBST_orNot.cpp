// Program to check given tree is a BST or not - coded by vHiren 
#include <iostream>
#include <malloc.h>
using namespace std;

// Basic Template
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Creates node and initializes their data
struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}
 
// Method to print tree 
void inOrder(struct node* root) {
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

// Method to verify given tree is BST or not - O(N) & O(H)
bool isBST(struct node* root) {
    static struct node* prev = nullptr; // Initially root does not have previous node

    if(root){
        if(!isBST(root->left))
            return false;
        if(prev && root->data <= prev->data)
            return false;

        prev = root;
        return isBST(root->right);
    }
    else{
        return true;
    }
}

// Driver code
int main() {
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

    inOrder(root); cout<<endl;

    // Method call
    if(isBST(root))
        cout<<"Given Tree is a BST";
    else
        cout<<"Given Tree is not a BST";

    return 0;
}