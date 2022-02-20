#include <bits/stdc++.h>
using namespace std;

bool isSafe(int mat[10][10], int i, int j, int n){
	for(int row=0;row<i; row++){
		if(mat[row][j] == 1){
			return false;
		} 
	}
	
	//check for left diagonal elements
	int x = i, y = j;
	
	while(x >= 0 and y >= 0){
		if(mat[x][y] == 1){
			return false;
		}
		x--;
		y--;
	}
	
	//check for right diagonal
	x = i, y = j;
	
	while(x >= 0 and y <=n ){
		if(mat[x][y] == 1){
			return false;
		}
		x--;
		y++;
	}
	
	return true;
}


bool solveNqueen(int mat[10][10], int i, int n){
	if(i > n){
		//Print the matrix
		for(int row=0; row <= n; row++){
			for(int j=0; j<=n; j++){
				cout<<mat[row][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		// return true;
		
		//To get all possible positons 
		return false;
	}
	
	
	//try to place the queen in current row and call on remaining part
	for(int j=0; j<=n; j++){
		if(isSafe(mat, i, j, n)){
			//place queen assuming i, j is right position
			mat[i][j] = 1;
			bool nextQueen = solveNqueen(mat, i+1, n);
			
			if(nextQueen)
			{
				return true;
			}
			
			//if loop is here means i, j was not the right position, therefore backtrack
			mat[i][j] = 0;
		}
	}
	
	//tried all positions but not able to place the queen
	return false;
	
}

int main() {
	int n;
	cin>>n;
	int board[10][10] = {0};
	
	solveNqueen(board, 0, n-1);
	
	return 0;
}