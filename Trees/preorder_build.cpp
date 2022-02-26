// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <iostream>
using namespace std;

class node{
	
	public:
	int data;
	node *left, *right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
	
};

node* buildTree(){
	int d;
	cin>>d;
	
	if(d == -1){
		return NULL;
	}
	
	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	
	return n;
}

int main() {
	// your code goes here
	node *root = buildTree();
	return 0;
}