// C++ Code implementation for above problem
#include <bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

// QItem for current location and distance
// from source location
class QItem {
public:
	int row;
	int col;
	int dist;
	QItem(int x, int y, int w)
		
	{
		 row = x;
		 col = y; 
		 dist = w;
	}
};

int minDistance(char grid[N][M])
{
	QItem source(0, 0, 0);
	bool visited[N][M];

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++){
			if(grid[i][j] == '0'){
				visited[i][j] = true;
			}
			else{
				visited[i][j]= false;
			}

			if(grid[i][j] == 's'){
				source.row = i;
				source.col = j;
			}
		}

	queue<QItem> q;
	q.push(source);
	visited[source.row][source.col] = true;

	while(!q.empty()){
		QItem p = q.front();
		q.pop();


		if(grid[p.row][p.col] == 'd'){
			return p.dist;
		}

		if(p.row-1 >= 0 && visited[p.row-1][p.col] == false){

			visited[p.row-1][p.col] = true;
			q.push(QItem(p.row-1, p.col, p.dist+1));
		}

		if(p.row+1 <N && visited[p.row+1][p.col] == false){

			visited[p.row+1][p.col] = true;
			q.push(QItem(p.row+1, p.col, p.dist+1));
		}

		if(p.col-1 >= 0 && visited[p.row][p.col-1] == false){

			visited[p.row][p.col-1] = true;
			q.push(QItem(p.row, p.col-1, p.dist+1));
		}


		if(p.col+1 <M && visited[p.row][p.col+1] == false){

			visited[p.row][p.col+1] = true;
			q.push(QItem(p.row, p.col+1, p.dist+1));
		}

	}

	return -1;
}

// Driver code
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char grid[N][M] = { { '0', '*', '0', 's' },
						{ 'd', '*', '*', '*' },
						{ '0', '*', '0', '*' },
						{ '*', '*', '0', '*' } };

	cout << minDistance(grid);
	return 0;
}
