/*
Input:
5
4 5 1 2 3
1

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int n, int key){
	int s=0, e=n-1;
	
	while(s <= e){
		int mid = (s+e)/2;
		if(arr[mid] == key){
			return mid;
		}
		
		//2nd case if key lies in first part
		else if(arr[s] <= arr[mid]){
			//2 cases
			//wheteher on left or right of mid
			if(key >= arr[s] and key <= arr[mid]){
				e = mid-1;
			}
			
			else{
				s = mid+1;
			}
		}
		
		//key lies in second part
		else{
			if(key >= arr[mid] and key <= arr[e]){
				s = mid+1;
			}
			
			else{
				e = mid-1;
			}
		}
	}
	
	return -1;
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
	
	cout<<find(arr, n, key);	
	return 0;
}