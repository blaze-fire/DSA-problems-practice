#include <bits/stdc++.h>
using namespace std;

bool canSolve(int mat[][9], int i, int j, int n, int number){
    
    //Row and column check
    for(int x = 0; x<n; x++){
        if(mat[x][j] == number || mat[i][x] == number){
            return false;
        }
    }

    //iterate in subgrid
    int rn = sqrt(n);   //(rn x rn) subgrid
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x = sx; x < sx+rn; x++){
        for(int y = sy; y < sy+rn; y++){
            if(mat[x][y] == number){
                return false;
            }
        }
    }

    return true;
}


bool SudokuSolver(int mat[][9], int i, int j, int n){
    
    //Base Case 
    if(i == n){
        for(int x=0; x<n; x++){
            for(int y = 0; y<n; y++){
                cout<<mat[x][y]<<"  ";
            }
            cout<<endl;
        }

        return true;
    }

    //Case row end
    if(j == n){
        return SudokuSolver(mat, i+1, 0, n);
    }

    //if a value already present
    if(mat[i][j] != 0){
        return SudokuSolver(mat, i, j+1, n);
    }

    //Recursive case
    for(int number = 1; number <= n; number++){
        
        if(canSolve(mat, i, j, n, number)){
            mat[i][j] = number;

            bool canSolveSudoku = SudokuSolver(mat, i, j+1, n);

            if(canSolveSudoku){
                return true;
            }
        }
    }

    //Backtrack
    mat[i][j] = 0;

    return false;
}



int main() {

    int mat[9][9] = 
        {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };

    SudokuSolver(mat, 0, 0, 9);

    return 0;
}
