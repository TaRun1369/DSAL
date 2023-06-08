#include<iostream>
#include<string>
using namespace std ;

class Node{
private :
	string word ;
	string meaning ;
	Node* left ;
	Node* right ;
public:
	Node(string word_ ="",string meaning_ =""){
		word = word_ ;
		meaning = meaning_ ;
		left = NULL ;
		right = NULL ;
	}

	friend class BST ;
};
class BST{
private:
	Node* root ;

public:


	BST(){
			root = NULL ;
		}
	void insert(string word , string meaning){
		Node* new_node = new Node(word , meaning);
		if(root == NULL){
			root = new_node ;
		}
		else {
			Node* curr = root ;
			Node* parent = NULL;
			while(curr!=NULL){
				if(word<curr->word){
					parent = curr ;
					curr = curr -> left ;
				}
				else{
					parent = curr ;
					curr = curr -> right ;
				}
			}
			if(word < parent->word){
				parent->left = new_node ;
			}
			else{
				parent->right = new_node ;
			}
		}
	}
	Node* get(){
		return root ;
	}
	bool search(string key,Node* &current, Node* &parentin){
		Node* curr = root ;
		int counter = 0 ;
		while(curr!=NULL){
			counter++ ;
			if(curr ->word == key){
				cout<<"the element found after - "<<counter<<" iterations"<<endl ;
				current = curr ;
				return true ;
			}
			else if (key < curr ->word ){
				parentin =  curr ;
				curr = curr->left ;
			}
			else{
				parentin = curr ;
				curr = curr->right ;
			}
		}
		parentin = NULL ;
		current = NULL ;
		return false ;
	}

	void remove(string x){
		Node* curr = NULL ;
		Node* parent = NULL ;
		Node* child = NULL;
		this->search(x,curr,parent);
		if(curr == NULL){
			cout<<"the element not present";
			return ;
		}
		if(curr->left != NULL && curr->right != NULL){
			Node* temp = curr->right ;
			while(temp->left!=NULL){
				temp = temp ->left ;
			}

			string strword = temp->word ;
			string strmeaning = temp->meaning ;
			this->remove(strword);
			curr->word = strword ;
			curr->meaning = strmeaning ;
		}
		else{
			if(curr->left != NULL){
				child = curr->left ;
			}
			else if(curr->right != NULL){
				child = curr->right ;
			}
			else {
				child = NULL ;
			}

			if(x<parent->word){
				parent->left = child ;
			}
			else{
				parent->right = child ;
			}
			delete curr ;
		}

	}

	void update(string key , string new_meaning){
			Node* curr = root ;
			while(curr!=NULL){
				if(curr ->word == key){
					curr->meaning = new_meaning ;
					return;
				}
				else if (key < curr ->word ){
					curr = curr->left ;
				}
				else{
					curr = curr->right ;
				}
			}
			cout<<"the element not found"<<endl ;
		}

	void  inorder(Node* n){
		if(n != NULL){
			inorder(n->left);
			cout<<n->word<<" - "<<n->meaning<<endl ;
			inorder(n->right);
		}
	}
	void  inorderR(Node* n){
		if(n != NULL){
			inorderR(n->right);
			cout<<n->word<<" - "<<n->meaning<<endl ;
			inorderR(n->left);
		}
	}
};

int main(){
	BST L ;
	while(true){
		int  menu ;
		cout<<"\n1)insert 2)print 3)print reverse 4)update 5)search 6)remove 0)Exit"<<endl;
		cin>>menu ;
		if(menu == 1){
			cout<<endl<<"Enter the word you want to enter"<<endl ;
			string word_ ;
			cin>>word_ ;
			cout<<endl<<"Enter the meaning of word"<<endl ;
			string meaning_ ;
			cin>>meaning_ ;
			L.insert(word_,meaning_);
		}
		else if(menu == 2){
			L.inorder(L.get());
		}
		else if(menu == 3){
			L.inorderR(L.get());
		}
		else if(menu == 4){
			cout<<endl<<"Enter the word you want to update"<<endl ;
			string word_ ;
			cin>>word_ ;
			cout<<endl<<"Enter the new meaning of word"<<endl ;
			string meaning_ ;
			cin>>meaning_ ;
			L.update(word_,meaning_);
		}
		else if(menu == 5){
			cout<<endl<<"Enter the word you want to search"<<endl ;
			string word_ ;
			cin>>word_ ;
			Node* curr = NULL ;
			Node* parent = NULL ;
			L.search(word_,curr,parent);
		}
		else if(menu == 6){
			cout<<endl<<"Enter the word you want to delete"<<endl ;
			string word_ ;
			cin>>word_ ;
			L.remove(word_);
		}
		else if(menu == 0){
			break ;
		}
		else {
			cout<<"enter valid input"<<endl ;
		}

	}
	return 1 ;
}