#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
    //check for column
    for(int row = 0; row<i; row++){
        if(board[row][j] == 1){
            return false;
        }
    }

    //check for left diagonal;

    int row = i;
    int col = j;

    while(row >= 0 && col >= 0){
        if(board[row][col] == 1){
            return false;
        }

        row--;
        col--;
    }

    //check for right diagonal

    row = i;
    col = j;

    while(row >= 0 && col < n){
        if(board[row][col] == 1){
            return false;
        }

        row--;
        col++;
    }


    return true;
}


bool NQueen(int board[][10], int i, int n){
    if(i == n){

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){
                    cout<<"Q";
                }

                else{
                    cout<<"_ ";
                }
            }

            cout<<endl;
        }
        cout<<endl<<endl;


        // (Hack) returning false will search for all valid configrations and print them
        return false;
    }


    for(int j=0; j<n; j++){
            if(isSafe(board, i , j, n)){
                board[i][j] = 1;

                bool nextQueenRakhPaye = NQueen(board, i+1, n);

                if(nextQueenRakhPaye){
                    return true;
                }

                board[i][j] = 0;
            }
    
    }

    return false;
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int board[10][10] = {0};
    int n;
    cin>>n;

    NQueen(board, 0, n);


    return 0;
}
