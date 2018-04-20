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

int max(int a, int b){
    return a > b ? a : b;
}

int calculateDiameter(Node* root, int* height){
    int lh = 0, rh = 0;
    int rDiameter = 0;
    int lDiameter = 0;
    
    if(root == NULL){
        *height = 0;
        return 0;
    }
    
    lDiameter = calculateDiameter(root->left, &lh);
    rDiameter = calculateDiameter(root->right, &rh);
    
    *height = max(lh, rh) + 1;
    
    return max(lh + rh + 1, max(lDiameter, rDiameter));
    
}

int main()
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    int height = 0;
    cout<<calculateDiameter(root, &height);
    return 0;
}