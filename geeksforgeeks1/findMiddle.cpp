#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void findMiddle(Node* head){
    
    Node* ptr1 = head;
    Node* ptr2 = head;
    if(ptr1->next == NULL || ptr1 == NULL)
        return;
    while(ptr1->next != NULL){
        ptr2 = ptr2->next;
        ptr1 = ptr1->next->next;
    }
    
    cout<<ptr2->data;
    
}

void push(Node** head, int data){
    Node* node = new Node;
    node->data = data;
    node->next = *head;
    *head = node;
}

int main()
{
    Node* head = NULL;
    int i;
 
    for (i=5; i>0; i--)
    {
        push(&head, i);
    }
    findMiddle(head);
    return 0;
}