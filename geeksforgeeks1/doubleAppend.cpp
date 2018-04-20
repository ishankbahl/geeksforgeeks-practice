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

void doubleAppend(Node* head){
    
    Node* ptr = head;
    int countZeroes = 0;
    Node* last;
    
    while(ptr != NULL){
        
        if(ptr->next && ptr->next->next && (ptr->data == ptr->next->data) && (ptr->next->next->data == 0)){
            ptr->data = ptr->data * 2;
            free(ptr->next);
            free(ptr->next->next);
            ptr->next = ptr->next->next->next;
            countZeroes += 2;
        }
        else if(ptr->next && ptr->next->data == 0){
            countZeroes++;
            free(ptr->next);
            ptr->next = ptr->next->next;
        }
        last = ptr;
        cout<<ptr->data<<" ";
        ptr = ptr->next;
        
    }
    
    while(countZeroes){
        countZeroes--;
        last->next = new Node();
        last->next->data = 0;
        last->next->next = NULL;
        last = last->next;
        cout<<last->data<<" ";
    }
    
}

int main()
{
    Node* head = NULL;
    push(&head, 4);
    push(&head, 0);
    push(&head, 3);
    push(&head, 3);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 0);
    push(&head, 4);
    push(&head, 4);
    doubleAppend(head);
    return 0;
}