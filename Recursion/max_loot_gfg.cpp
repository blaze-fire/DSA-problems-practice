#include<bits/stdc++.h>
using namespace std;

//

/*
int maxStolen(int arr[], int n){
    if(n==0)
        return 0;

    int val1 = arr[0];
    if(n==1)
        return val1;

    int val2  = max(arr[0], arr[1]);
    if(n==2)
        return val2;

    int temp;

    for(int i=2; i<n; i++){
         temp = max(val1+arr[i], val2);
         val1 = val2;
         val2 = temp; 
    }

    return temp;
}*/

int maxStolen(int arr[], int n){
    if(n<=0){
        return 0;
    }

    int select = arr[n-1] + maxStolen(arr, n-2);

    int not_select = maxStolen(arr, n-1);

    return max(select, not_select);
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

    cout<<maxStolen(arr, n);

    return 0;
}