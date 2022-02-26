#include<iostream>
using namespace std;

bool isValid(int stalls[], int n, int cows, int min_sep){
	int last_cow = stalls[0], count = 1;
	for(int i=1; i<n; i++){
		if(stalls[i] - last_cow >= min_sep){
			count++;
			last_cow = stalls[i];
			if(count == cows){
				return true;
			}
		}
	}
	
	return false;
}

int main(){
	
	
		int stalls[] = {1, 2, 4, 8, 9};
        int num_stalls = 5;
        int cows = 3;
        
		
		int start = 0, end = stalls[num_stalls-1] - stalls[0];
		int ans = 0;
			
		while(start <= end){
			int mid = (start + end)/2;
			
			bool ifCanPlace = isValid(stalls, num_stalls, cows, mid);
			
			if(ifCanPlace){
				ans = mid;
				start = mid+1;
			}
			
			else{
				end = mid-1;
			}
		}
		
		cout<<ans<<endl;
	
	
	return 0;
}