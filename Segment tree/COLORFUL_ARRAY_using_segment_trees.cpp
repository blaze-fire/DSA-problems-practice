/* (Using Segment trees)

												CLFLARR - COLORFUL ARRAY


You have been given an array of n unpainted elements. By unpainted, we mean that each element initially has a value of 0. You have to process q queries of the form l r c, in which you paint all the elements of the array from index l to index r with color c. Assume that, each new color currently being applied to an element overrides its previous color. Output the color of each element after all the queries have been processed.

Note: The problem is guaranteed to be solved using C or C++ programming language.

Input
The first line of input consists of two integers n and q. Next q lines consists of 3 integers l, r and c denoting the starting index, ending index and the color respectively.

1 <= n <= 200000
1 <= q <= 200000
1 <= l <= r <= n
1 <= c <= 1 000 000 000
Output
Output the final color of each element starting from index 1 on a new line.

Example
Input
4 3
1 3 2
2 4 6
2 3 7
Output:
2
7
7
6
Input
10 5
3 9 13
1 4 9
2 10 14
2 7 10
6 9 44
Output
9
10
10
10
10
44
44
44
44
14


*/


#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

void updateRangeLazy(ll tree[], ll ss, ll se, ll l, ll r, ll color, ll index, ll lazy[]){
	
	// update lazy value 
	if(lazy[index] != 0){
		tree[index] = lazy[index];
		
		if(se != ss){
			lazy[2*index] = lazy[index];
			lazy[2*index+1] = lazy[index];
		}
		
		lazy[index] = 0;
	}
	
	//no overlap
	if(r < ss || l > se){
		return;
	}
	
	//complete overlap
	if(ss >= l and se <= r){
		tree[index] = color;
		
		if(ss != se){
			lazy[2*index] = color;
			lazy[2*index + 1] = color;
		}
		
		return;
	}
	
	//recursive case
	ll mid = (ss + se)/2;
	
	updateRangeLazy(tree, ss, mid, l, r, color, 2*index, lazy);
	updateRangeLazy(tree, mid+1, se, l, r , color, 2*index+1, lazy);
	
	return;	
}

void printLazy(ll tree[], ll ss, ll se, ll index, ll lazy[]){
	
	if(lazy[index] != 0){
		tree[index] = lazy[index];
		
		if(ss != se){
			lazy[2*index] = lazy[index];
			lazy[2*index + 1] = lazy[index];
		}
		
		lazy[index] = 0;
	}
	
	//only print leaf nodes
	if(ss == se){
		cout<<tree[index]<<endl;
		return;
	}
	
	//recursive case
	ll mid = (ss + se)/2;
	printLazy(tree, ss, mid, 2*index, lazy);
	printLazy(tree, mid+1, se, 2*index+1, lazy);
		
	return;
}

int main(){	
	ll m, n;
	cin>>m>>n;
	
	ll tree[4*m + 1] = {0};		//uncolored array is 0
	
	ll lazy[4*m+1] = {0};
	
	for(ll i=0; i<n; i++){
		ll qs, qe, color;
		cin>>qs>>qe>>color;
		updateRangeLazy(tree, 1, m, qs, qe, color, 1, lazy);
	}
	
	printLazy(tree, 1, m, 1, lazy);
	return 0;
}