#include<iostream>
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

void detectSorted(Node* head){
    Node* ptr = head;
    if(ptr == NULL){
        cout<<1;
    }
    int num = ptr->data;
    ptr = ptr->next;
    while(ptr != NULL){
        if(num > ptr->data){
            cout<<0;
            return;
        }
        num = ptr->data;
        ptr = ptr->next;
    }
    cout<<1;
}

int main(){
    
    Node* head = NULL;
    push(&head ,7);
    push(&head ,5);
    push(&head ,4);
    push(&head ,8);
    
    detectSorted(head);
    return 0;
}
