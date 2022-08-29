#include<iostream>
#include<limits.h>
#include <queue>
using namespace std;

bool isvalid(int books[], int n, int m, int max_lim){
	
	int count = 1;
	int temp_sum = 0;
	
	for(int i=0; i<n; i++){
		if(books[i] > max_lim){
			return false;
		}

		if(temp_sum + books[i] > max_lim){
			temp_sum = books[i];
			count++;
		}	
		else{
			temp_sum += books[i];
		}
	}
	
	return (count <= m);
}

int main(){
	int books[] = {12,34,67,90};
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
