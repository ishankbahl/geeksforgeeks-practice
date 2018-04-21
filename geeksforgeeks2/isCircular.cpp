#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

bool isCircular(Node* head){
    
    if(head == NULL)
        return true;
    
    Node* temp = head->next;
    
    while(temp != NULL && temp != head)
        temp = temp->next;
    
    return (temp == head);
}

int main(){
    
    Node* head = newNode(1);
    
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
 
    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;
 
    // Making linked list circular
    head->next->next->next->next = head;
 
    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;
    
    return 0;
}