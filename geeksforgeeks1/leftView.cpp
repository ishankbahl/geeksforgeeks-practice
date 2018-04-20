#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void leftView(Node* root){
    
    if(root == NULL)
        return;
        
    stack<pair<Node*, int>> s;
    unordered_map<int, int> m;
    int value = 0;
    int max_value = -1;
    s.push(make_pair(root, value));
    
    while(!s.empty()){
        
        pair<Node*, int> p = s.top();
        Node* node = p.first;
        value = p.second;
        s.pop();
        
        if(max_value < value)
            max_value = value;
        
        if(m.find(value) == m.end())
            m[value] = node->data;
        
        if(node->right != NULL)
            s.push(make_pair(node->right, value + 1));
            
        if(node->left != NULL)
            s.push(make_pair(node->left, value + 1));
        
    }
    for(int i = 0; i <= max_value; i++){
        cout<<m[i]<<" ";
    }
    
}

int main(){
    
    Node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
 
    leftView(root);
    
    return 0;
    
}