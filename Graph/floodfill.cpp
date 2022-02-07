#include<bits/stdc++.h>
using namespace std;
  
class FloodFill{
    int R, C;
    char mat[1000][1000];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    FloodFill(int r, int c){
        R = r;
        C = c;
    }

    void add_points(int i, int j, char ch){
        mat[i][j] = ch;
    }


    void floodfill(int i, int j, char ch, char colour){
        if(i<0 || j<0 || i>=R || j>=C){
            return;
        }

        if(mat[i][j] != ch){
            return;
        }

        mat[i][j] = colour;

        for(int k=0; k<4; k++){
            floodfill(i+dx[k], j+dy[k], ch, colour);
        }
    }


    void print(){
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    
    }
};
  
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    

    int r, c;
    char ch;
    cin>>r>>c;

    FloodFill f(r,c);

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            cin>>ch;
            f.add_points(i, j, ch);
        }    
    
    f.floodfill(3, 1, '2', '3');

    f.print(); 

    return 0;
}