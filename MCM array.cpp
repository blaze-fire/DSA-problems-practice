#include <bits/stdc++.h>
using namespace std;

int mn_ = INT_MAX;

int solve(int arr[], int i, int j){
	if(i >= j){
		return 0;
	}
	
	
	for(int k=i; k<=j-1; k++){
		int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
		mn_ = min(mn_, temp_ans);
	}
	
	return mn_;
}

int main() {
	// your code goes here
	int arr[] = {40, 20, 30, 10, 30};
	int n = sizeof(arr)/sizeof(int);
	
	cout<<solve(arr, 1, n-1);
	return 0;
}