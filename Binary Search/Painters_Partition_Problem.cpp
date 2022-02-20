#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

bool isValid(ll board[], int n, int k, ll max_lim){
	ll temp = max_lim, count=1;
	for(int i=0; i<n;){
		if(temp - board[i] >= 0){
			temp -= board[i];
			i++;
		}
		
		else{
			count++;
			temp = max_lim;
			if(count > k){
				return false;
			}
		}
	}
	
	if(count <= k){
		return true;
	}
	
	return false;
}

int main(){	
	int k;
	cin>>k;
	
	int n;
	cin>>n;
	
	ll board[n];
	ll max_limit = 0;
	for(int i=0; i<n; i++){
		cin>>board[i];
		max_limit += board[i];
	}
	
	ll start = board[n-1], end = max_limit;
	ll ans = INT_MAX;
	while(start <= end){
		ll mid = (start + end)/2;
		bool ispossible = isValid(board, n, k, mid);
		
		if(ispossible){
			end = mid-1;

			if(mid < ans)
				ans = mid;
		}
		
		else{
			start = mid+1;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}