#include <iostream>
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

Node* reverseList(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* next;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;    
    }
}

int main(){
    
    Node* head = NULL;
   
    push(&head, 20);
    push(&head, 4);
    push(&head, 15); 
    push(&head, 85);    
    
    reverseList(&head);                      
    printList(head);    
    return 0;

    
}