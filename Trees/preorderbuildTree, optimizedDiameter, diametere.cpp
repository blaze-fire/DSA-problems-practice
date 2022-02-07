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

//preorderbuild
node* preorderbuildTree(){
	int d;
	cin>>d;
	
	if(d == -1){
		return NULL;
	}
	
	node* n = new node(d);
	n->left = preorderbuildTree();
	n->right = preorderbuildTree();
	
	return n;
}

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

//helper function for diameter of tree 
int height(node* root){
	if(root == NULL){
		return 0;
	}
	
	int h1 = height(root->left);
	int h2 = height(root->right);
	
	return 1 + max(h1, h2);
}

int diameter(node* root){
	if(root == NULL){
		return 0;
	}
	
	int D1 = height(root->left) + height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);
	
	return max(D1, max(D2, D3));
}


//Optimized Diameter
class hdPair{	//helper class to store height and diameter
	public:
	int height;
	int diameter;
};


hdPair optimizedDiameter(node* root){
	hdPair p;
	
	if(root == NULL){
		p.height = p.diameter = 0;
		return p;
	}
	
	hdPair Left = optimizedDiameter(root->left);
	hdPair Right = optimizedDiameter(root->right);
	
	p.height = max(Left.height, Right.height) + 1;
	
	int D1 = Left.height + Right.height;
	int D2 = Left.diameter;
	int D3 = Right.diameter;
	
	p.diameter = max(D1, max(D2, D3));
	
	return p;
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

int main() {
	
	//node *root = preorderbuildTree();		//tree built from preorder input 
	
	node *root = level_order_build(); 		//tree built from  level order input	
	//level_order_print(root);
	//cout<<diameter(root);
	
	//Optimized diameter
	cout<<optimizedDiameter(root).diameter;
	
	return 0;
}