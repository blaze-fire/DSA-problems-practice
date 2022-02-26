#include <bits/stdc++.h>
using namespace std;


bool ratInmaze(char maze[10][10], int sol[][10], int i, int j, int m, int n, int &cnt){

    if(i == m && j == n){

        sol[m][n] = 1;
        cnt++;

        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j ++){
                cout<<sol[i][j]<<"  ";
            }
            cout<<endl;
        }

        cout<<endl<<endl;

        return true;
    }

    // if outside the cell
    if(i>m || j>n){
        return false;
    }

    //if cannot travel the cell
    if(maze[i][j] == 'X'){
        return false;
    }

    //assume solution exists
    sol[i][j] = 1;

    bool rightExists = ratInmaze(maze, sol, i, j+1, m, n, cnt);
    bool leftExists = ratInmaze(maze, sol, i+1, j, m, n, cnt);


    sol[i][j] = 0;


    if(rightExists || leftExists){
        return true;
    }


    return false;

}



int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    char maze[10][10] = { 
                    "0000",
                    "00X0",
                    "000X",
                    "0X00",
    };

    int sol[10][10] = {0};

    int cnt = 0;
    ratInmaze(maze, sol, 0, 0, 3, 3, cnt);

    cout<<endl<<"Number of ways : "<<cnt<<endl;

    return 0;
}
