#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

int countLeaves(Node* root){
    
    if(root == NULL)
        return 0;
    
    int count = 0;
    
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    
    return count + countLeaves(root->right) + countLeaves(root->left);
    
}

int main()
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout<<countLeaves(root);
    return 0;
}