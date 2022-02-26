#include<bits/stdc++.h>
using namespace std;

//MergeSort (Divide and Conquer)


void merge(int arr[], int l, int r){
    int mid = (l+r)/2;
    int i = l;
    int j = mid+1;
    int k = l;

    int temp[2*r];

    while(i <= mid && j<= r){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }

        else{
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= r){
        temp[k++] = arr[j++];
    }

    for(int i=l; i <= r; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r){
    if(l >= r)
        return;

    int mid = (l+r)/2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    //merge 
    merge(arr, l, r);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}