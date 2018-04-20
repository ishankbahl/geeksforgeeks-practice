#include<iostream>
using namespace std;

int main(){
    int size = 4, temp;
    int arr[size][size] = {{1,  2,  3,  4},
                            {5,  6,  7,  8},
                            {9,  10, 11, 12},
                            {13, 14, 15, 16}};
    for(int i = 0, j = size - 1; i < j; i++, j--){
        temp = arr[i][i];
        arr[i][i] = arr[j][j];
        arr[j][j] = temp;
        
        temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}