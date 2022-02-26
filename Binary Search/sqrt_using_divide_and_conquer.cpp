#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	int s=0, e=n;
	float ans=-1;
	while(s <= e){
		int mid = (s+e)/2;
		
		if(mid*mid == n){
			ans = mid;
			cout<<"perfect square : "<<ans;
			return 0;
		}
		
		if(mid*mid < n){
			ans = mid;
			s = mid+1; 
		}
		
		else{
			e = mid-1;
		}
		
	}
	
	int tol;
	cin>>tol;

	float inc = 0.1;
	for(int times=1; times<=tol; times++){
		while(ans*ans <= n){
			ans += inc;
		}
		ans -= inc;
		inc /= 10;
		
	}
	cout<<ans<<endl;
	
	return 0;
}