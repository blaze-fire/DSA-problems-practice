#include<iostream>
#include<limits.h>
#include <queue>
using namespace std;

bool isvalid(int books[], int n, int m, int max_lim){
	
	int count = 1;
	int temp_lim = max_lim;
	
	for(int i=0; i<n; i++){
		if(temp_lim - books[i] >= 0){
			temp_lim -= books[i];
		}	
		else{
			count++;
			temp_lim = max_lim;
			if(count >= m && i != n-1){
				return false;
			}
		}
	}
	
	if(count <= m){
		return true;
	}
	
	return false;
}

int main(){
	int books[] = {10, 20, 30, 40};
	int n = 4, m = 2;
	int pages = 0;
	
	for(int i=0; i<n; i++){
		pages += books[i];
	}
	
	int start = books[n-1], end = pages;
	int ans = INT_MAX;
	
	while(start <= end){
		int mid = (start + end)/2;
		
		bool Canread = isvalid(books, n, m, mid);
		
		if(Canread){
			end = mid-1;
			if(mid < ans){
				ans = mid;
			}
		}
		
		else{
			start = mid+1;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}