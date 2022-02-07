#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int r){
    int mid = (l+r)/2;
    int i = l;
    int j = mid+1;
    int k = l;

    int temp[2*r];

    int cnt = 0;

    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }

        else{
            cnt += mid - (i-1);
            temp[k++] = arr[j++];
        }
    }

    //fill the array

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= r){
        temp[k++] = arr[j++];
    }

    for(int i = l; i<=r; i++){
        arr[i] = temp[i];
    }

    return cnt;
}

int inversion_count(int arr[], int l, int r){
    if(l >= r)
        return 0;

    int mid = (l+r)/2;

    int x = inversion_count(arr, l, mid);
    int y = inversion_count(arr, mid+1, r);
    int z = merge(arr, l, r);

    return x+y+z;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 5, 2, 6, 3, 0};

    int n = sizeof(arr)/sizeof(int);

    cout<<inversion_count(arr, 0, n-1);



    //Brute Force
    /*
    int cnt = 0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                cnt++;
            }
        }
    } 

    cout<<cnt;*/
    return 0;
}