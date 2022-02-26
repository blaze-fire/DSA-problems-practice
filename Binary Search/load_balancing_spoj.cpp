/*
Input :
10
0 0 100 0 0 0 0 0 0 0

Output: 70
*/

#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin>>n;
	
	int arr[n], sum = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	
	
	if(sum % n == 1){
		cout<<"-1";
		return 1;
	}

	int target = sum/n;
	int ans = INT_MIN;
	
	for(int i=0; i<n-1; i++){
		
		int j = i+1;

		//size of the left part
		int left = j;
		
		//only calculate for left array as it will include answer for right part as the excess jobs in one side is equal to lesser jobs in other part
		int left_sum=0;
		for(int k=0; k<j; k++){
			left_sum += arr[k];
		}

		int required = abs(left*target - left_sum);
		ans = max(ans, required);
		
	}
	
	cout<<ans;
	
	return 0;
}