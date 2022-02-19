#include <bits/stdc++.h>
using namespace std;

void generate_subsequence(char in[], char out[], int i, int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	
	out[j] = in[i];
	generate_subsequence(in, out, i+1, j+1);
	
	generate_subsequence(in, out, i+1, j);
	return;	
}

int main() {
	char in[] = "abc";
	char out[100];
	generate_subsequence(in, out, 0, 0);
	return 0;
}