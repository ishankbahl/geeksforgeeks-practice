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

void deleteNodes(Node** head, int x){
    Node* current = *head;
    Node* prev = NULL;
    
    while(current != NULL){
        if(current->data > x){
            if(prev != NULL)
                prev->next = current->next;
            else 
                *head = current->next;
            delete current;
            if(prev != NULL)
                current = prev->next;
            else
                current = *head;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    
}

int main()
{
    // Create list: 7->3->4->8->5->1
    Node* head = NULL;
    push(&head,1);
    push(&head, 5);
    push(&head, 8);
    push(&head, 4);
    push(&head, 3);
    push(&head, 7);
    
    deleteNodes(&head, 6);
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    return 0;
}