#include <bits/stdc++.h>
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

void findBottomView(Node* root){
    
    if(root == NULL)
        return;
    
    queue<pair<Node*, int>> q;
    unordered_map<int, int> m;
    int min, max;
    
    int value = 0;
    q.push(make_pair(root, value));
    min = 0;
    max = 0;
    
    while(!q.empty()){
        pair<Node*, int> p = q.front();
        q.pop();
        Node* node = p.first;
        int data = node->data;
        value = p.second;
        if(value < min)
            min = value;
        else if(value > max)
            max = value;
        m[value] = data;
        if(node->left != NULL)
            q.push(make_pair(node->left, value - 1));
        if(node->right != NULL)
            q.push(make_pair(node->right, value + 1));
    }
    
    for(int i = min; i <= max; i++){
        cout<<m[i]<<" ";
    }
    
}

int main()
{
    Node * root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right-> left = newNode(10);
    root->left->right->right = newNode(14);
    
    findBottomView(root);

    return 0;
}