#include <bits/stdc++.h>
using namespace std;

bool ratInMaze(char mat[10][10], char sol[10][10], int i, int j, int n, int m){
	if(i == m && j == n){
		sol[m][n] = '1';
		
		//print the path
		for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		return true;
	}
	
	if(i > n || j > m){
		return false;
	}
	
	if(mat[i][j] == 'X'){
		return false;
	}
	
	//Assume solution exits through current cell
	sol[i][j] = '1';
	
	//Now check if path possible through down or right cells 
	bool checkLeft = ratInMaze(mat, sol, i, j+1, m, n);
	bool checkRight = ratInMaze(mat, sol, i+1, j, m, n);
	
	//Backtrack after checking from both directions
	sol[i][j] = '0';
	
	if(checkRight || checkLeft){
		return true;
	}
	
	return false;
}

int main() {
	char maze[10][10] = {
			"0000",
			"00X0",
			"000X",
			"0X00",
	};
	

	char sol[10][10];
	
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            sol[i][j] = '0';
    }

    int m = 4, n=4;
	
	bool ans = ratInMaze(maze, sol, 0, 0, m-1, n-1);
	
	if(!ans){
		cout<<"NO path";
	}
	return 0;
}