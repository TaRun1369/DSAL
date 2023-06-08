// Sunay Bhoyar
// 21110 SE 1
// 18/05/2023

#include<iostream>
#include<string>
#include<vector>
using namespace std ;


template<class T>
class queue{
	T arr[20];
	int front;
	int rear;
public:

	queue(){
		front=-1;
		rear=-1;
	}

	bool isfull(){
		if(rear==19){
			return true;
		}
		else{
			return false;
		}
	}

	bool isempty(){
		if(front==rear && rear==-1){
			return true;
		}
		else{
			return false;
		}
	}

	void push(T x){
		if(isfull()){
			cout<<"Queue is full"<<endl;
		}
		else if(isempty()){
			front++;
			rear++;
			arr[rear]=x;
		}
		else{
			rear++;
			arr[rear]=x;
		}
	}
	T pop(){
		if(isempty()){
			cout<<"Queue is empty"<<endl;
			return NULL ;
		}
		else if(front==rear){
			T res =  arr[front];
			front=-1;
			rear=-1;
			return res ;
		}
		else{
			T res  = arr[front];
			front=front+1;
			return res ;
		}
	}
};
template<class T>
class stack{
	int top;
	T arr[20];
public:
	bool isempty(){
		if(top==-1){
			return true;
		}
		return false;

	};
	bool isfull(){
		if(top==19){
			return true;
		}
		return false;
	};
	void push(T x){
		if(isfull()){
			cout<<"stack is full"<<endl;
		}
		else{
			top++;
			arr[top]=x;
		}
	}
	T pop(){
		if(isempty()){
			cout<<"Stack is empty"<<endl;
			return NULL ;
		}
		else{
			top--;
			return arr[top+1];
		}
	}

	stack(){
		top=-1;
	}

};
class Node{
	string data;
	Node *left = NULL;
	Node *right = NULL;
public:

	Node(string x){
		data = x;
		left = right = NULL;
	}
	friend class obst;
};

class obst{
	Node *root;
	int nW;

	float **W,**C,**R;

public:
	obst(int n){

		root = NULL;
		nW = n;

		W = new float*[nW];
		R = new float*[nW];
		C = new float*[nW];

		for(int i=0;i<=nW;i++){
			W[i] = new float[nW+1];
			C[i] = new float[nW+1];
			R[i] = new float[nW+1];
		}
	}

	Node* getRoot(){
		return root;
	}

	void print(){
		for(int i=0;i<=nW;i++){
			for(int j=0;j<=nW;j++){
				cout<<W[i][j] <<" \t\t";
			}
			cout<<endl;
		}
		cout<<endl;

		cout<<endl;
		for(int i=0;i<=nW;i++){
			for(int j=0;j<=nW;j++){
				cout<<C[i][j] <<" \t\t";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<endl;
		for(int i=0;i<=nW;i++){
			for(int j=0;j<=nW;j++){
				cout<<R[i][j] <<" \t\t";
			}
			cout<<endl;
		}

	}


	void calculateWeight(float *p,float *q,string* input){
		int diffrence = 0 ;
		while(diffrence <= nW){
			int i = 0 ;
			int j = i + diffrence ;
			while(j <= nW){
				if( i == j){
					W[i][j] = q[i] ;
				}
				else{
					W[i][j] = W[i][j - 1] + p[j] + q[j] ;
				}
				i ++ ;
				j = i + diffrence ;
			}
			diffrence ++  ;
		}
		diffrence = 0 ;
		while(diffrence <= nW){
			int i = 0 ;
			int j = i + diffrence ;
			while(j <= nW){
				if( i == j ){
					R[i][j] = C[i][j] = 0 ;
				}
				else {
					double cost = 9999.999 ;
					for (int k = i + 1 ; k <= j ; k ++){
						if(cost > C[i][k-1] + C[k][j]){
							C[i][j] = C[i][k-1] + C[k][j] ;
							R[i][j] = k ;
							cost =  C[i][k-1] + C[k][j] ;
						}
					}
					C[i][j] += W[i][j] ;
				}
				i++ ;
				j = i + diffrence ;
			}
			diffrence ++  ;
		}
		root = create_tree(0,nW ,input);
	}

	Node* create_tree(int i,int j , string* input)
	{
		if(i != j)
		{
			int k = R[i][j];
			Node *t = new Node(input[k]);
			t->left = create_tree(i,k-1,input);
			t->right = create_tree(k,j,input);

			return t;
		}
		else
		{
			return NULL;
		}
	}
	void inorder(Node *t){
		if(t != NULL){
			inorder(t->left);
			cout<<t->data<<"\t";
			inorder(t->right);
		}
	}
	void preoder(Node *t){
			if(t != NULL){
				cout<<t->data<<"\t";
				preoder(t->left);
				preoder(t->right);
			}
		}

};
int main(){
	obst t(4);
	string input[] = {" ", "A", "B", "C","D"};
	float p[]= {0.0, 0.3,0.05,0.15,0.4};
	float q[] = {0.1, 0.02,0.02, 0.09, 0.07,};

	t.calculateWeight(p,q,input);
	t.print();
	cout<<endl ;
	t.inorder(t.getRoot());
	cout<<endl ;
	t.preoder(t.getRoot());


	return 0;
}




