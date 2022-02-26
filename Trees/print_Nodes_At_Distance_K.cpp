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



void printAtLevelK(node* root, int k){
	if(root == NULL){
		return;
	}
	
	if(k == 0){
		cout<<root->data<<"	";
		return;
	}
	
	printAtLevelK(root->left, k-1);
	printAtLevelK(root->right, k-1);
}

int printNodesAtDistanceK(node* root, node* target, int k){
	//base case
	if(root == NULL){
		return -1;
	}
	
	//reached the target node
	if(root == target){
		printAtLevelK(root, k);
		return 0;
	}
	
	//other case
	int DL = printNodesAtDistanceK(root->left, target, k);
	if(DL != -1){
		//2 cases
		
		//print the current node
		if(DL+1 == k){
			cout<<root->data;
		}
		
		//print some nodes in right subtree
		else{
			printAtLevelK(root->right, k-DL-2);
		}
		
		//tell its parents its at distance 1+DL from target
		return 1 + DL;
	}
	
	//Similiarly if target in right subtree
	int DR = printNodesAtDistanceK(root->right, target, k);
	if(DR != -1){
		//2 cases
		
		//print the current node
		if(DR+1 == k){
			cout<<root->data;
		}
		
		//print some nodes in left subtree
		else{
			printAtLevelK(root->left, k-DR-2);
		}
		
		//tell its parents its at distance 1+DR from target
		return 1 + DR;
	}
	
	return -1;
	
}



int main() {
	// Input : 1 2 3 4 5 -1 6 -1 -1 7 8 -1 -1 -1 -1 9 10 -1 -1 -1 -1 (Ans : 9 10 4 1)
	
	node* root = level_order_build();
	node *target = root;
	target = target->left->right;
	printNodesAtDistanceK(root, target, 2);
	return 0;
}