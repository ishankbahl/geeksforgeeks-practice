#include<bits/stdc++.h>
using namespace std;

int find_min_index(queue<int> q, int last_index){
    int min_index = 0;
    int min = q.front();
    q.pop();
    for(int i = 1; i <= last_index; i++){
        if(q.front() < min){
            min_index = i;
            min = q.front();
        }
        q.pop();
    }
    return min_index;
}

void insertMinToRear(queue<int> &q, int min_index){
    int min, curr;
    for(int i = 0; i <= q.size(); i++){
        curr = q.front();
        q.pop();
        if(i != min_index)
            q.push(curr);
        else
            min = curr;
    }
    q.push(min);
}

void sortQueue(queue<int>& q){
    int min_index;
    for(int i = 1; i <= q.size(); i++){
        min_index = find_min_index(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
    
}

int main(){
    
    queue<int> q;
    q.push(30);
    q.push(11);
    q.push(15);
    q.push(4);
    
    // Sort queue
    sortQueue(q);
    
    // Print sorted queue
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
    
}