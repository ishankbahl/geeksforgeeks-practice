#include<iostream>
using namespace std;

int main(){
    int size = 5;
    int half = size/2;
    int arr[size][size] = { {  2,   9,   1,   4,  -2},
                      {6,   7   ,2,  11   ,4},
                      {4 ,   2 , 9 ,  2   ,4},
                      {1  , 9 ,  2  ,  4 , 4},
                      {0   ,2,   4   , 2,  5 }};
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for(int i = 0, j = size - 1; i < size; i++, j--){
        if(i < size/2){
            sum1 += arr[i][i];
            sum2 += arr[i][j];
        }
        else if (i > size/2){
            sum3 += arr[i][i];
            sum4 += arr[i][j];
        }
    }
    if((sum1 == sum2) && (sum3 == sum4) && (sum1 == sum3) && (sum1 == arr[half][half]))
        cout<<true;
    return 0;
}