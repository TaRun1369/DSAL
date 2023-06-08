#include <iostream>

using namespace std;
class entry{
  public: 
  long int number;
  string name;
  entry(){
    number = -1;
    name = "---------";
  }
  
  
  entry(long int n , string ns){
    number = n;
    name = ns;
  }
};

class HashTable{
    int size;
    entry * data;
    public:
    HashTable(int ss){
        size = ss;
        data = new entry[ss];
    }
    int hashfunc(long int key){
        return key%size;
    }    
    void insertwithoutReplacement(entry newE){
        int hc = hashfunc(newE.number);
        if(data[hc].number == -1){
            data[hc] = newE;
        }
        else{
            int temp = hc+1;
            while(temp != hc){
                if(temp == size){
                    temp= 0;
                }
                if(data[temp].number == -1){
                    data[temp] = newE;
                    return;
                }
                if(temp!= hc)
                temp++;
            }
            cout<<"jaghah nhi hai"<<endl;
        }
        
    }
    
    void insertwithReplacement(entry newE){
        int hc = hashfunc(newE.number);
        if(data[hc].number == -1){
            data[hc] = newE;
            }
            else{
                if(hc == hashfunc(data[hc].number)){
                    int temp = hc+1;
                    while(temp != hc){
                        if(temp == size){
                            temp = 0;
                        }
                        if(data[temp].number == -1){
                            data[temp] = newE;
                            return;
                        }
                        if(temp != hc)
                        temp++;
                    }
                    
                    
                }
                else{
                    entry retrive = data[hc];
                    data[hc] = newE;
                    insertwithReplacement(retrive);
                    return;
                }
                cout<<"jaghah nhi hai soooory"<<endl;
            }
    }
    
    void display(){
        for(int i = 0;i<size;i++){
            cout<<i<<" "<<data[i].number<<"->"<<data[i].name<<endl;
        }
    }
    
    int search(long int key){
        int hc  = hashfunc(key);
        if(data[hc].number == -1){
            cout<<"nhi hai ye wali key"<<endl;
            return -1;
        }
        else{
            if(data[hc].number == key){
                cout<<"yahi hai"<<hc<<" pe "<<endl;
                return hc;
            }
            else{
                int temp = hc + 1;
                int cnt = 1;
                while(temp != hc){
                    if(temp == size){
                        temp = 0;
                    }
                    if(data[temp].number = key){
                        cout<<"voila deprivated by "<<cnt<<" at position"<<temp<<endl;
                        return temp;
                    }
                    if(temp != hc){
                    temp++;
                    cnt++;
                    }
                }
                cout<<"nhi hai pura dekha pakka"<<endl;
                return -1;
            }
            
        }
    }
    
    void deletee(long int key){
        int loc = search(key);
        if(loc == -1){
            cout<<"koi tha he nhi kisko udau"<<endl;
            return;
        }
        else{
            int lastloc = loc;
            int temp = loc+1;
            data[loc].number = -1;
            data[loc].name = "---------";
            while(temp!= loc){
                if(temp == size){
                    temp = 0;
                }
                if(lastloc == hashfunc(data[temp].number)){
                    data[lastloc] = data[temp];
                    data[temp].number = -1;
                    data[temp].name = "---------";
                    lastloc = temp;
                }
                if(temp != loc)
                temp++;
            }
        }
    }
    
    void update(long int key,long int newN,string newName){
        int loc = search(key);
        if(loc != -1){
            data[loc].name = newName;
            data[loc].number = newN;
        }
        else{
            cout<<"aisa koi hai he nhi chutiye"<<endl;
            return;
        }
    }
    
};



int main()
{
    int size;
    cout<<"Size dalo sir"<<endl;
    cin>>size;
     HashTable *h;
     h = new HashTable(size);
     
     h->insertwithoutReplacement(entry(10,"tarun"));
     h->insertwithoutReplacement(entry(11,"tarun1"));
     h->insertwithoutReplacement(entry(20,"tarun2"));
     h->insertwithoutReplacement(entry(21,"tarun3"));
     h->insertwithoutReplacement(entry(22,"tarun4"));
     h->insertwithoutReplacement(entry(105,"tarun5"));
     
     h->deletee(10);
     
     h->display();
     
     
     

    return 0;
}