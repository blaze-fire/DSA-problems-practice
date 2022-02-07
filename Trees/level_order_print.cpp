#include <iostream>
#include <queue>

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

void level_order_print(node* root){
	queue <node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* top = q.front();
		q.pop();
		
		if(top == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		
		else{
			cout<<top->data<<" ";
			if(top->left)
				q.push(top->left);

			if(top->right)
				q.push(top->right);

		}
	}
}

int main() {
	node *root = buildTree();
	level_order_print(root);
	return 0;
}