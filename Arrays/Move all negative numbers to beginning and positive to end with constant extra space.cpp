#include<iostream>
using namespace std;

int main(){
	
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

	int i=0, j=0;

	int n = sizeof(arr)/sizeof(int);

	for(; i<n; i++){
		if(arr[i] < 0){
			std::swap(arr[i], arr[j]);
			j++;
		}
	}

	for(i = 0; i<n; i++){
		cout<<arr[i]<<"	";
	}

	return 0;
}