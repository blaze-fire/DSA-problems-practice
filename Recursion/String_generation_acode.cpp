#include <bits/stdc++.h>
using namespace std;

void generate_strings(char in[], char out[], int i, int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	
	int digit = in[i] - '0';
	char ch = digit + 'A' - 1;
	out[j] = ch;
	//one digit at a time
	generate_strings(in, out, i+1, j+1);
	
	//two digit at a time
	if(in[i+1] != '\0'){
		int second_digit = in[i+1] - '0';
		int dig = digit*10 + second_digit;
		if(dig <= 26){
			ch = dig + 'A' - 1;
			out[j] = ch;
			generate_strings(in, out, i+2, j+1);
		}
	}
	return;
	
}

int main() {
	char in[100];
	cin>>in;
	
	char out[100];
	generate_strings(in, out, 0, 0);
	return 0;
}