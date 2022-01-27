#include <iostream>

using namespace std;

int partition(int arr[], int start, int end){
    int i = start-1;

    for(int j=start; j <= end-1; j++){
        if(arr[j] <= arr[end]){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i+1], arr[end]);

    return i+1;
}

void quicksort(int arr[], int start, int end){
    if(start >= end){
        return;
    }

    int pivot = partition(arr, start, end);

    quicksort(arr, start, pivot-1);
    quicksort(arr, pivot+1, end); 
}

int main() {
    int arr[] = {2, 7, 8, 6, 1, 5, 4};
    int n = sizeof(arr)/sizeof(int);

    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
