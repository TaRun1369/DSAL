Sunay Bhoyar																				ASS 4
#include<iostream>
#include<string>
using namespace std ;

class entry{

public:
	long int number ;
	string name ;
	entry(long int number_ = -1 , string name_ = "----------"){
		number = number_ ;
		name = name_;
	}
};

class hashTable{
	int size;
	entry *data ;

	int hashFunction(long int key){
		int res = 0 , temp = 0;
		temp = key / 100000000 ;
		res += temp ;
		temp = key / 1000000 - (temp*100) ;
		res += temp ;
		temp = key / 1000000;
		temp = key/ 10000 - (temp*100) ;
		res += temp ;
		temp = key / 10000;
		temp = key / 100 - (temp*100) ;
		res += temp ;
		temp = key / 100;
		temp = key / 1 - (temp*100) ;
		res += temp ;
		temp = key / 1;
		return res % size;
	}

public:
	hashTable(int size_=10){
		size = size_ ;
		data = new entry [size];
	}
	void insertWithOutReplacement(entry newEntry){
		int hc = hashFunction(newEntry.number);
		if(data[hc].number == -1){
			data[hc] = newEntry ;
		}
		else{
			int temp = hc + 1;
			while(temp!=hc){
				if(temp == size){
					temp = 0 ;
				}
				if(data[temp].number == -1){
					data[temp] = newEntry ;
					return ;
				}
				temp++;
			}
			cout<<"sorry the hashTable is now at max limit";
		}
	}
	void insertWithReplacement(entry newEntry){
			int hc = hashFunction(newEntry.number);
			if(data[hc].number == -1){
				data[hc] = newEntry ;
			}
			else{
				if(hc == hashFunction(data[hc].number)){
					int temp = hc + 1;
					while(temp!=hc){
						if(temp == size){
							temp = 0 ;
						}
						if(data[temp].number == -1){
							data[temp] = newEntry ;
							return ;
						}
						temp++;
					}
				}
				else{
					entry retrive  = data[hc] ;
					data[hc] = newEntry ;
					insertWithReplacement(retrive);
					return ;
				}

				cout<<"sorry the hashTable is now at max limit";
			}
		}

	int search(long int key){
		int hc = hashFunction(key);
		if(data[hc].number == -1){
			cout<<"the data not present" <<endl;
			return -1 ;
		}
		if(data[hc].number == key){
			cout<<"the element found at correct hash location of "<<hc<<endl;
			return hc ;
		}
		else{
				int cnt = 1 ;
				int temp = hc + 1;
				while(temp!=hc){
					if(temp == size){
						temp = 0 ;
					}
					if(data[temp].number == key){
						cout<<"the element found devaited "<<cnt<<" position from "<<hc<<" to "<<temp<<" location "<<endl;
						return temp;
					}
					temp++;
					cnt ++ ;
				}
			cout<<"the data not present";
			return -1 ;
			}
		}

	void update(long int key , long number_ , string name_){
		int loc = search(key);
		if(loc != -1){
			data[loc].number = number_ ;
			data[loc].name = name_ ;
 		}

	}

	void displayTable(){
		for (int i = 0 ; i < size ; i ++){
			cout<<i<<" "<<data[i].number<<" "<<data[i].name<<endl ;
		}
	}

	void deleteElem(long int key){
		int loc = search(key);
		if(loc == -1){
			cout<<"the element is not present"<<endl ;
		}
		else{
			int hc = hashFunction(key);
			data[loc].number = -1;
			data[loc].name =  "----------";
			int lastloc = loc ,temp = loc+1 ;
			while(temp!=hc){
				if(temp == size){
					temp = 0 ;
				}
				if(hashFunction(data[temp].number)==hc){
					data[lastloc] = data[temp] ;
					data[temp].number = -1;
					data[temp].name =  "----------";
					lastloc = temp ;
				}
				temp ++ ;
			}
		}
	}

};
int main(){
	int size = 0 ;
	hashTable *H ;
	cout<<"enter the size of the hash table\n";
	cin>>size ;

	H = new hashTable(size);

	int menu;
		while(true){
			cout<<"\n\nSelect the option\n1)enter data with replacement\n2)enter data without replacement\n3)search data\n4)update data\n5)delete data\n6)display data\n0)exit\n";
			cin>>menu ;
			if(menu == 1){
				long int number_ = 0;
				string name_ = "----------";
				cout<<"\nenter the number\n";
				cin>>number_;
				cout<<"\nenter the name\n";
				cin>>name_ ;
				H->insertWithReplacement(entry(number_,name_));

			}
			else if(menu == 2){
				long int number_ = 0;
				string name_ = "----------";
				cout<<"\nenter the number\n";
				cin>>number_;
				cout<<"\nenter the name\n";
				cin>>name_ ;
				H->insertWithOutReplacement(entry(number_,name_));
			}
			else if(menu == 3){
				long int number_ = 0;
				cout<<"\nenter the key you want to search\n";
				cin>>number_;
				H->search(number_);

			}
			else if(menu == 4){
				long int keynumber_ = 0;
				cout<<"\nenter the key you want to search\n";
				cin>>keynumber_;
				long int number_ = 0;
				string name_ = "----------";
				cout<<"\nenter the new number\n";
				cin>>number_;
				cout<<"\nenter the new name\n";
				cin>>name_ ;
				H->update(keynumber_,number_,name_);

			}
			else if(menu == 5){
				long int keynumber_ = 0;
				cout<<"\nenter the key you want to search\n";
				cin>>keynumber_;
				H->deleteElem(keynumber_);

			}
			else if(menu == 6){
				H->displayTable();
			}
			else if(menu == 0){
				break;
			}
			else{
				cout<<"Enter vaild option\n";
			}

		}
}