// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
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

node* level_order_build(){
	int d;
	cin>>d;
	
	node *root = new node(d);
	queue<node*> q;
	
	q.push(root);
	
	while(!q.empty()){
		node* current = q.front();
		q.pop();
		
		int c1, c2;
		cin>>c1>>c2;
		
		if(c1 != -1){
			current->left = new node(c1);
			q.push(current->left);
		}
		
		if(c2 != -1){
			current->right = new node(c2);
			q.push(current->right);
		}
	}
	
	return root;
} 

void level_order_Print(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* current = q.front();
		q.pop();
		
		if(current == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		
		else{
			cout<<current->data<<" ";
			
			if(current->left != NULL){
				q.push(current->left);
			}
			
			if(current->right != NULL){
				q.push(current->right);
			}
		}
	}
}

void PrintAtDistance_K(int k, node* root){
	if(root == NULL){
		return;
	}
	
	if(k == 0){
		cout<<root->data<<" ";
		return;
	}
	
	PrintAtDistance_K(k-1, root->left);
	PrintAtDistance_K(k-1, root->right);
}


int main() {
	//Input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1 (ans = 4 5 6)
	node* root = level_order_build();
	//level_order_Print(root);
	PrintAtDistance_K(2, root);
	
	return 0;
}