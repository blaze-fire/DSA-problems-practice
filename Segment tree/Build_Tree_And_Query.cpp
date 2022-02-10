#include<iostream>
#include<climits>
using namespace std;

void buildtree(int arr[], int tree[], int start, int end, int index){
	if(start == end){
		tree[index] = arr[start];
		return;
	}
	
	int mid = (start + end)/2;
	
	buildtree(arr, tree, start, mid, 2*index);
	buildtree(arr, tree, mid+1, end, 2*index+1);
	
	tree[index] = min(tree[2*index], tree[2*index+1]);
	return;
}

int query(int tree[], int ss, int se, int qs, int qe, int index){
	
	//complete overlap
	if(ss >= qs and se <= qe){
		return tree[index];
	}
	
	//no overlap
	if(qe < ss || qs > se){
		return INT_MAX;
	}

	//partial overlap
	int mid = (ss + se)/2;
	int left = query(tree, ss, mid, qs, qe, 2*index);
	int right = query(tree, mid+1, se, qs,qe, 2*index+1);
	
	return min(left, right);
}

int main(){	
	int arr[] = {1, 3, 2, -5, 6, 4};
	
	int n = sizeof(arr)/sizeof(int);
	
	int *tree = new int [4*n+1];
	
	buildtree(arr, tree, 0, n-1, 1);
	
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<query(tree, 0, n-1, l, r, 1)<<endl;
	}
	
	return 0;
}