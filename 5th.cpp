#include<iostream>
#include<string>
using namespace std ;

class entry{

public:
	string word;
	string meaning ;
	entry* next ;
	entry(string word_ = "-----" , string meaning_ = "-----"){
		word = word_ ;
		meaning = meaning_;
		next = NULL;
	}
};

class hashTableClosed{
	int size = 10;
	entry *data[10] ;

	int hashFunction(string key){
		int res = 0 ;
		for(long unsigned int i = 0 ; i < key.length() ; i ++){
			res += (int)key[i] ;
		}
		return res % size;
	}
public:


	hashTableClosed(){
		for(int i = 0 ; i < size ; i++ ){
			data[i] = NULL ;
		}
	}
	void insert(string word_ = "-----" , string meaning_ = "-----"){
			entry *newEntry = new entry(word_,meaning_);
			int hc = hashFunction(newEntry->word);
			if(data[hc] == NULL){
				data[hc] = newEntry ;
			}
			else{
				entry* temp = data[hc];
				while(temp->next!=NULL){
					temp = temp->next;
				}
				temp->next = newEntry;
			}
		}

	entry* search (string key_){
		int hc = hashFunction(key_);
		if(data[hc] == NULL){
			cout<<"data not found"<<endl ;
			return NULL;
		}
		if(data[hc]->word == key_){
			cout<<"the data found at "<<hc<<" index of hashtable at first postion in chain"<<endl ;
			return data[hc];
		}
		else{
			entry *temp = data[hc] ;
			int count = 1 ;
			while(temp!=NULL){
				if(temp->word == key_){
					cout<<"the data found at "<<hc<<" index of hashtable at postion "<< count<<" in chain"<<endl ;
					return temp;
				}
				count ++ ;
				temp = temp->next;
			}
			cout<<"data not found"<<endl ;
			return NULL;
		}
	}

	void deleteElem(string key_){
		int hc = hashFunction(key_);
		entry* temp2 = NULL ;
		if(data[hc] == NULL){
			cout<<"data not found"<<endl ;
			return ;
		}
		if(data[hc]->word == key_){
			temp2 = data[hc] ;
			data[hc] = temp->next ;
			delete temp2 ;
		}
		else{
			entry *temp = data[hc] ;
			while(temp->next!=NULL){
				if(temp->next->word == key_){
					temp2 = temp ->next ;
					temp ->next = temp->next ->next;
					delete temp2 ;
					return ;
				}
				temp = temp->next;
			}
			cout<<"data not found"<<endl ;
			return;
		}

	}

	void update(string key_ ,string meaning_ ){
		entry* temp = search(key_);
		if(temp == NULL){
			cout<<"data absent"<<endl ;
		}
		else{
			temp->meaning = meaning_ ;
		}
	}

	void displayTable(){
		for (int i = 0 ; i < size ; i ++){
			entry* temp = data[i];
			cout<<i;
			while(temp != NULL){
				cout<<" "<<temp->word<<" "<<temp->meaning <<"  ->   ";
				temp = temp->next;
			}
			cout<<endl ;
		}
	}

};
int main(){

	hashTableClosed H;
	H.displayTable();

	int menu;
		while(true){
			cout<<"\n\nSelect the option\n1)enter data\n2)search data\n3)update data\n4)delete data\n5)display data\n0)exit\n";
			cin>>menu ;
			if(menu == 1){
				string word_ = "-----";
				string meaning_ = "-----";
				cout<<"\nenter the word\n";
				cin>>word_;
				cout<<"\nenter the meaning\n";
				cin>>meaning_ ;
				H.insert(word_,meaning_);

			}
			else if(menu == 2){
				string key_;
				cout<<"\nenter the key you want to search\n";
				cin>>key_;
				H.search(key_);

			}
			else if(menu == 3){
				string key_;
				cout<<"\nenter the key you want to update\n";
				cin>>key_;
				string newMeaning_;
				cout<<"\nenter the new meaning\n";
				cin>>newMeaning_;
				H.update(key_,newMeaning_);

			}
			else if(menu == 4){
				string key_;
				cout<<"\nenter the key you want to update\n";
				cin>>key_;
				H.deleteElem(keynumber_);

			}
			else if(menu == 5){
				H.displayTable();
			}
			else if(menu == 0){
				break;
			}
			else{
				cout<<"Enter vaild option\n";
			}
		}
}
