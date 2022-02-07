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



//level order build
node* level_order_build(){
	int d;
	cin>>d;
	
	node* root = new node(d);

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



//level order print
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



int replaceWithSum(node* root){
	if(root == NULL){
		return 0;
	}
	
	if(root->left == NULL and root->right == NULL){
		return root->data;
	}
	
	int temp = root->data;
	root->data = replaceWithSum(root->left) + replaceWithSum(root->right);
	return temp + root->data;
}



int main() {
	
	node *root = level_order_build(); 		//tree built from  level order input	
	replaceWithSum(root);
	level_order_print(root);
	
	return 0;
}