#include<iostream>
#include<climits>
using namespace std;

bool isValid(int rank[], int n, int prata, int max_time){
	int temp_count=0;
	
	for(int i=0; i<n; i++){
		int temp_sum=0, j=1;
		while(temp_sum + j*rank[i]<= max_time){
			temp_sum += j*rank[i];
			j++;
		}
		temp_count += j-1;
	}
	
	if(temp_count >= prata){
		return true;
	}
	
	return false;
}

int main(){
	int tc;
	cin>>tc;
	
	while(tc--){
		int prata;
		cin>>prata;
		
		int n;
		cin>>n;
		
		int rank[n];
		
		for(int i=0; i<n; i++){
			cin>>rank[i];
		}
		
		int start = 0;
		int end = rank[0]*(prata)*(prata+1)/2;
		
		int ans = INT_MAX;
		
		while(start <= end){
			int mid = (start + end)/2;
			
			bool ifpossible = isValid(rank, n, prata, mid);
			
			if(ifpossible){
				end = mid-1;
				if(mid < ans){
					ans = mid;
				}
			}
			
			else{
				start = mid+1;
			}
		}
		
		if(ans == INT_MAX){
			cout<<rank[0]*(prata)*(prata+1)/2<<endl;
		}
		
		else
			cout<<ans<<endl;
	}
	
	return 0;
}