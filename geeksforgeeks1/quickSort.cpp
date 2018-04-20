#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *b = *a;
    *a = temp;
}

int partition(int arr[],int start,int end){
    if(start > end)
        return -1;
    int pivot = arr[end];
    int partition_index = start - 1;
    for(int i = start; i < end; i++){
        if(arr[i] <= pivot){
            partition_index++;
            swap(arr[partition_index], arr[i]);
        }
    }
    swap(arr[partition_index + 1], arr[end]);
    return partition_index + 1;
}

void quicksort(int arr[], int start, int end){
    
    int partition_index = partition(arr, start, end);
    
    if(partition_index != -1){
        quicksort(arr, start, partition_index - 1);
        quicksort(arr, partition_index + 1, end);
    }
    
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, 5);
    for(int i = 0; i < 6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
