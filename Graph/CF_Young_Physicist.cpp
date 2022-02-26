/*A. Young Physicist

		https://codeforces.com/problemset/problem/69/A

*/

#include<stdio.h>

int main()
{/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	int n;
	scanf("%d", &n);
	
	int x_net_Force = 0, y_net_Force = 0, Net_magnitude = 0;
	int x, y, m;

	while(n--){
		scanf("%d %d %d", &x, &y, &m);
		x_net_Force += x;
		y_net_Force += y;
		Net_magnitude += m;
	}

	if(x_net_Force == 0 && y_net_Force == 0 && Net_magnitude == 0){
		printf("YES");
	}

	else{
		printf("NO");
	}

	return 0;
}


/*
Eg. 
6 5
4 0
4 5
0 1
0 2
0 3
*/