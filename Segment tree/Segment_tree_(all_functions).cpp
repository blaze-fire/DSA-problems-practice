#include<iostream>
#include<climits>
using namespace std;

void buildtree(int arr[], int tree[], int start, int end, int index){
	//leaf node
	if(start == end){
		tree[index] = arr[start];
		return;
	}
	
	int mid = (start + end)/2;
	
	//left subtree
	buildtree(arr, tree, start, mid, 2*index);
	
	//right subtree
	buildtree(arr, tree, mid+1, end, 2*index+1);
	
	tree[index] = min(tree[2*index], tree[2*index+1]);
	return;
}

int query(int tree[], int ss, int se, int qs, int qe, int index){
	
	//Complete Overlap
	if(ss >= qs and se <= qe){
		return tree[index];
	}
	
	//No Overlap
	if(qe < ss || qs > se){
		return INT_MAX;
	}
	
	//Partial Overlap
	int mid = (ss + se)/2;
	int left = query(tree, ss, mid, qs, qe, 2*index);
	int right = query(tree, mid+1, se, qs, qe, 2*index+1);
	
	return min(left, right);
}

void updateNode(int tree[], int ss, int se, int idx, int increment, int index){
	
	//index not in range
	if(idx < ss || idx > se){
		return;
	}
	
	//leaf node
	if(ss == se){
		tree[index] += increment; 
		return;
	}
	
	//continue to find leaf node in left and right subtree
	int mid = (ss + se)/2;
	updateNode(tree, ss, mid, idx, increment, 2*index);
	updateNode(tree, mid+1, se, idx, increment, 2*index+1);
	
	//update values in tree before you return  
	tree[index] = min(tree[2*index], tree[2*index+1]);
	return;
}

void updateRange(int tree[], int ss, int se, int l, int r, int inc, int index){
	
	// out of bounds
	if(l > se || r < ss){
		return;
	}
	
	//leaf node
	if(ss == se){
		tree[index] += inc;
		return;
	}
	
	int mid = (ss + se)/2;
	updateRange(tree, ss, mid, l, r, inc, 2*index);
	updateRange(tree, mid+1, se, l, r, inc, 2*index+1);
	
	tree[index] = min(tree[2*index], tree[2*index+1]);
	return;
}

void updateRangeLazy(int tree[], int ss, int se, int l, int r, int inc, int index, int lazy[]){
	
	// update lazy value 
	if(lazy[index] != 0){
		tree[index] += lazy[index];
		
		if(se != ss){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		
		lazy[index] = 0;
	}
	
	//no overlap
	if(r < ss || l > se){
		return;
	}
	
	//complete overlap
	if(ss >= l and se <= r){
		tree[index] += inc;
		
		if(ss != se){
			lazy[2*index] += inc;
			lazy[2*index + 1] += inc;
		}
		
		return;
	}
	
	//recursive case
	int mid = (ss + se)/2;
	
	updateRangeLazy(tree, ss, mid, l, r, inc, 2*index, lazy);
	updateRangeLazy(tree, mid+1, se, l, r , inc, 2*index+1, lazy);
	
	tree[index] = min(tree[2*index], tree[2*index+1]);
	return;	
}

int queryLazy(int tree[], int ss, int se, int qs, int qe, int index, int lazy[]){
	
	if(lazy[index] != 0){
		tree[index] += lazy[index];
		
		if(ss != se){
			lazy[2*index] += lazy[index];
			lazy[2*index + 1] += lazy[index];
		}
		
		lazy[index] = 0;
	}
	
	//Query logic
	
	//No Overlap	
	if(ss > qe or se < qs){
		return INT_MAX;
	}
	
	//complete overlap
	if(ss >= qs and se<= qe){
		return tree[index];
	}
	
	//recursive case
	int mid = (ss + se)/2;
	int left = queryLazy(tree, ss, mid, qs, qe, 2*index, lazy);
	int right = queryLazy(tree, mid+1, se, qs, qe, 2*index+1, lazy);
		
	return min(left, right);
}

int main(){	
	int arr[] = {1, 3, 2, -5, 6, 4};
	
	int n = sizeof(arr)/sizeof(int);
	
	int *tree = new int [4*n+1];
	int lazy[4*n+1] = {0};
	
	buildtree(arr, tree, 0, n-1, 1);
	
	//updateNode(tree, 0, n-1, 3, 10, 1);
	//updateRange(tree, 0, n-1, 3, 5, 10, 1);
	updateRangeLazy(tree, 0,n-1, 0, 2, 10, 1, lazy);
	updateRangeLazy(tree, 0,n-1, 0, 4, 10, 1, lazy);
	cout<<"Q 1-1 "<<queryLazy(tree, 0, n-1, 1, 1, 1, lazy)<<endl;
	updateRangeLazy(tree, 0,n-1, 3, 4, 10, 1, lazy);
	cout<<"Q 2-2 "<<queryLazy(tree, 0, n-1, 3, 5, 1, lazy)<<endl;
	

	
	return 0;
}