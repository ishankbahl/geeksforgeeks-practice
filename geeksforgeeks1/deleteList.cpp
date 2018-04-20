#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deleteList(Node** head){
    Node* current = *head;
    Node* next;
    
    while(current == NULL){
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

void push(Node** head, int data){
    Node* node = new Node();
    node->data = data;
    node->next = *head;
    *head = node;
}

int main()
{
    Node* head = NULL;
    
    push(&head, 1);
    push(&head, 4);
    push(&head, 1); 
    push(&head, 12);
    push(&head, 1);
    deleteList(&head);
    return 0;
}