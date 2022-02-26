/*
Q) 
Given an array of numbers where each element represents the max number of jumps 
that can be made forward from that element. For each array element, count 
the number of ways jumps can be made from that element to reach the end 
of the array. If an element is 0, then a move cannot be made through that element.
 The element that cannot reach the end should have a count “-1”.
 

Examples:

Input : {3, 2, 0, 1}
Output : 2 1 -1 0
For 3 number of steps or jumps that 
can be taken are 1, 2 or 3. The different ways are:
3 -> 2 -> 1
3 -> 1

For 2 number of steps or jumps that 
can be taken are 1, or 2. The different ways are:
2 -> 1

For 0 number of steps or jumps that 
can be taken are 0. 
One cannot move forward from this point.

For 1 number of steps or jumps that 
can be taken are 1. But the element is at
the end so no jump is required.

Input : {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9}
Output : 52 52 28 16 8 -1 -1 4 2 1 0


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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

	int count[n] = {0};

	for(int i=n-2; i>=0; i--){
		if(arr[i] == 0){
			count[i] = -1;
			continue;
		}

		if (arr[i]>=n-i-1)
			count[i]++;


		for(int j=i+1;j<n-1 && j<=arr[i]+i; j++){
			if(count[j] != -1){
				count[i] += count[j]; 
			}
		}

	}	

	for(int i=0; i<n; i++)
		cout<<count[i]<<"	";	

    return 0;

}