#include <bits/stdc++.h>
using namespace std;

void reverseQ(queue<int>& q){
    if(q.empty()){
        return;
    }
    
    int data = q.front();
    q.pop();
    
    reverseQ(q);
    
    q.push(data);
    
}

int main(){
    queue<int> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    reverseQ(Queue);
    while(!Queue.empty()){
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
    return 0;
}