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

bool detectLoop(Node* head){
    
    Node* ptr1 = head;
    Node* ptr2 = head;
    
    if(ptr1 == NULL)
        return 0;
    
    while(ptr1 && ptr2 && ptr1->next != NULL){
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
        if(ptr1 == ptr2)
            return 1;
    }
    return 0;
}

int main()
{
    Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
    cout<<detectLoop(head);
    return 0;
}