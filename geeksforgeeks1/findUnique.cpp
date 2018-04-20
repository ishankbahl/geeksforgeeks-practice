#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void push(Node** head, int data){
    Node* node = new Node();
    node->data = data;
    node->next = *head;
    *head = node;
}

void findUnique(Node* head){
    Node* ptr = head;
    unordered_map<int, int> hash;
    
    if(ptr == NULL){
        cout<<NULL;
    }
    
    while(ptr != NULL){
        hash[ptr->data]++;
        ptr = ptr->next;
    }
    ptr = head;
    while(ptr){
        if(hash[ptr->data] == 1)
            cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    Node* head = NULL;
    
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 5);
    push(&head, 3);
    push(&head, 2);
    push(&head, 4);
    push(&head, 4);
    push(&head, 1);
    
    findUnique(head);
    
    return 0;
}