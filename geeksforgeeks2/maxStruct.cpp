#include <iostream>
using namespace std;

struct Height{
  int feet;
  int inches;
};

void findMax(Height arr[], int size){
    int max = -1;
    for(int i = 0; i < size; i++){
        if((arr[i].feet*12 + arr[i].inches) > max)
            max = arr[i].feet*12 + arr[i].inches;
    }
    cout<<max;
}

int main(){
    
    Height arr[] = {
        { 1, 3 },
        { 10, 5 },
        { 6, 8 },
        { 3, 7 },
        { 5, 9 }
    };
    
    findMax(arr, 5);
    
    return 0;
}