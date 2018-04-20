#include<iostream>
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
}

bool isSumProperty(Node* node){
    
    int left_data = 0, right_data = 0;
    
    if(node == NULL || (node->right == NULL && node->left == NULL))
        return true;
        
    if(node->right != NULL)
        right_data = node->right->data;
        
    if(node->left != NULL)
        right_data = node->right->data;
        
    if(((right_data + left_data) == node->data) && isSumProperty(node->right) && isSumProperty(node->left))
        return true;
    else 
        return false;
    
}

int main()
{
    Node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(5);
    root->right->right = newNode(2);
    cout<<isSumProperty(root);
    return 0;
}