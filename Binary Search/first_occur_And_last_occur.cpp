/*
Input:
8
2 3 3 4 4 4 1 6
4

Output:
first occur at : 3, and last occur at : 5

*/

#include <bits/stdc++.h>
using namespace std;

int first_occurence(int arr[], int n, int key){
	int s = 0, e = n-1;
	int ans = -1;
	
	while(s <= e){
		int mid = (s+e)/2;
		
		if(arr[mid] == key){
			//if key found dont stop and keep finding the first occurence
			ans = mid;
			e = mid-1;
		}
		
		else if(arr[mid] < key){
			s = mid+1;
		}
		
		else if(arr[mid] > key){
			e = mid-1;
		}
	}
	
	return ans;
}

int last_occurence(int arr[], int n, int key){
	int s = 0, e = n-1;
	int ans = -1;
	
	while(s <= e){
		int mid = (s+e)/2;
		
		if(arr[mid] == key){
			//if key found dont stop and keep finding the first occurence
			ans = mid;
			s = mid+1;
		}
		
		else if(arr[mid] < key){
			s = mid+1;
		}
		
		else if(arr[mid] > key){
			e = mid-1;
		}
	}
	
	return ans;
}


int main() {
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	
	cout<<"first occur at : "<<first_occurence(arr, n, key)<<", and last occur at : "<<last_occurence(arr, n, key);
	
	return 0;
}