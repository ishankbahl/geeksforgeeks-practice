#include<iostream>
using namespace std;

int min(int a, int b, int c){
    int num = (a > b) ? b : a;
    num = (c > num) ? num : c;
    return num;
}

int main(){
    int R = 6, C = 5;
    bool arr[R][C] = {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    int arr1[R][C];
    for(int i = 0; i < R; i++){
        arr1[i][0] = arr[i][0];
    }
    for(int i = 0; i < R; i++){
        arr1[0][i] = arr[0][i];
    }
    int max = 0;
    for(int i = 1; i < R; i++){
        for(int j = 1; j < C; j++){
            if(arr[i][j] == 0)
                arr1[i][j] = 0;
            else {
                arr1[i][j] = min(arr1[i][j - 1], arr1[i - 1][j], arr1[i - 1][j - 1]) + 1;
                if (max < arr1[i][j])
                    max = arr1[i][j];
            }
        }
    }
    cout<<max;
    return 0;
}