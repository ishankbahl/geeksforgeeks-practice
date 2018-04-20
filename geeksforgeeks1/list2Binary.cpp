#include<iostream>
#include<queue>
using namespace std;

struct listNode{
    int data;
    listNode* next;
};

struct treeNode{
    int data;
    treeNode* right;
    treeNode* left;
};

void push(listNode** head, int data){
    listNode* node = new listNode();
    node->data = data;
    node->next = *head;
    *head = node;
}

treeNode* newNode(int data){
    treeNode* node = new treeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(treeNode* root){
    if(root){
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

void list2Binary(listNode* head){
    queue<treeNode*> q;
    if(head == NULL)
        return;
    listNode* temp = head;
    treeNode* parent = newNode(head->data);
    q.push(parent);
    listNode* temp2 = head;
    while(temp != NULL){
        treeNode* node = q.front();
        q.pop();
        if(temp->next != NULL){
            node->left = newNode(temp->next->data);
            q.push(node->left);
            temp2 = temp2->next;
            
            if(temp->next->next != NULL){
                node->right = newNode(temp->next->next->data);
                q.push(node->right);
                temp2 = temp2->next;
            }
            
        }
        if(temp == temp2){
            temp = temp->next;
        }
        else{
            temp = temp2;
        }
    }
    
    inorderTraversal(parent);
    
}

int main(){
    listNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10);
    list2Binary(head);
    return 0;
}