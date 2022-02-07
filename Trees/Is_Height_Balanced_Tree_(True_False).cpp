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


pair<int, bool> isHeightBalanced(node *root){
	pair<int, bool> Left, Right;
	if(root == NULL){
		return make_pair(0, true);	
	}
	
	Left = isHeightBalanced(root->left);
	Right = isHeightBalanced(root->right);
	
	int height = max(Left.first, Right.first) + 1;
	
	if(abs(Left.first - Right.first) <= 1 and Left.second and Right.second){
		return make_pair(height, true);
	}
	
	return make_pair(height, false);
}


int main() {
	
	//Input : 1 2 3 4 5 -1 6 -1 -1 7 8 -1 -1 -1 -1 9 10 -1 -1 -1 -1
	
	node *root = level_order_build(); 		//tree built from  level order input	
	//level_order_print(root);
	if(isHeightBalanced(root).second){
		cout<<"Balanced";
	}
	else{
		cout<<"Not Balanced";		
	}
	return 0;
}