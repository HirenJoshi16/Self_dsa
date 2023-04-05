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

// Finds the inorder predecessor of given node
struct node* inorderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

// Perfoms deletion
struct node* deleteNode(struct node* root, int value){
    struct node* iPre = NULL;

    // In case when tree is empty
    if(root == NULL){
        return root;
    }
    // If at that value node then Deletes that node
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
    // Search the node to be deleted
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    // Deletion strategy when the node is found
    else{
        // Find the inorder Predecessor or successor of that node
        iPre = inorderPredecessor(root);
        // Now copy iPre's data to that root node
        root->data = iPre->data;
        // After copying search the ipre's data node [as we know ipre can be found at left subtree], now delete the ipre node
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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

    preOrderI(root);
    cout<<endl;
    root = deleteNode(root, 15);
    preOrderI(root);
    return 0;
}