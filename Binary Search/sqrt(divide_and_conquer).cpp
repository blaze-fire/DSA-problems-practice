#include<iostream>
#include<climits>
using namespace std;

int main(){	
	int n;
	cin>>n;
	
	int p;
	cin>>p;
	
	int start = 0, end = n;
	float ans=-1;
	while(start <= end){
		float mid = (float)(start + end)/2;

		if(mid * mid == n){
			cout<<"sqrt : "<<mid<<endl;
			break;
		}
		
		if(mid*mid < 50){
			end = mid - 1;
			ans = mid;
		}
		
		else{
			start = mid+1;
		}
	}
	
	float inc = 0.1;
	
	for(int times = 1; times <=p; times++){
		while(ans*ans <= n){
			ans += inc;
		}
		ans -= inc;
		inc = inc/10;
	}
	
	cout<<ans<<endl;
	
	return 0;
}