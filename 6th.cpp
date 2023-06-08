/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;


class Node{
  string data;
  Node* next;
  
  public: 
  Node(string d){
      data = d;
      next = NULL;
      
  }
  
  friend class Graph;
};


class Graph{
  Node **adjMat;
  string *p;
  int v;
  
  public:
    Graph(){
        cout<<"Enter number of cities"<<endl;
        cin>>v;
        p = new string[v];
        string s;
        for(int i = 0;i<v;i++){
            cout<<"Enter name of city "<<endl;
            cin>>s;
            p[i] = s;
        }
        adjMat = new Node*[v];
        for(int i = 0 ;i<v;i++){
            adjMat[i] = NULL;
        }
        
        cout<<"Enter edges - "<<endl;
        char ch = 'y';
        string v1,u1;
        while(ch == 'y'){
            cout<<"Enter first city"<<endl;
            cin>>v1;
            cout<<"Enter second city"<<endl;
            cin>>u1;
            Node* nN = new Node(u1);
            Node* temp = adjMat[search(v1)];
            if(temp == NULL){
                adjMat[search(v1)] =  nN;
            }
            else{
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = nN;
            }
            
            cout<<"Do u want to continue"<<endl;
            cin>>ch;
        }
        
    }
    
    int search(string s){
        for(int i = 0;i<v;i++){
            if(p[i] == s){
                return i;
            }
        }
        
    }
    
    void show(){
      for(int i = 0;i<v;i++){
          cout<<"city - > "<<p[i]<<" ";
          Node* temp = adjMat[i];
          while(temp){
              cout<<temp->data<<", ";
              temp = temp->next;
          }
          cout<<endl;
      }  
    }
    
    void dfs(string start){
        // int i = search(start);
        stack<string> s;
        s.push(start);
        int visited[v] ;
        for(int i = 0;i<v;i++){
            visited[i] = 0;
        }
        visited[search(start)] = 1;
        while(!s.empty()){
            string tem = s.top();
            s.pop();
            cout<<tem<<" ";
            int temint = search(tem);
            Node* wN = adjMat[temint];
            while(wN){
                if(!visited[search(wN->data)]){
                    visited[search(wN->data)] = 1;
                    s.push(wN->data);
                }
                wN = wN->next;
            }
        }
        cout<<endl;
        
        
        
    }
    
    void bfs(string start){
        int i = search(start);
        queue<string> s;
        s.push(start);
        int visited[v] ;
        for(int i = 0;i<v;i++){
            visited[i] = 0;
        }
        visited[i] = 1;
        while(!s.empty()){
            string tem = s.front();
            s.pop();
            cout<<tem<<" ";
            int temint = search(tem);
            Node* wN = adjMat[temint];
            while(wN){
                if(!visited[search(wN->data)]){
                    visited[search(wN->data)] = 1;
                    s.push(wN->data);
                }
                wN = wN->next;
            }
        }
        cout<<endl;
        
        
        
    }
    
    
    
};
int main()
{
    Graph G;
    int choice = 0;
    
    char ch='y';
    while(ch == 'y'){
        cout<<"\n 1. Create Graph\n 2. Diaplay Adj \n 3. DFS ";
        
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Created "<<endl;
            break;
            case 2:
            G.show();
            break;
            case 3:
            
            G.dfs("pune");
            break;
            default: cout<<"Invalid choice"<<endl;
            case 4:
            G.bfs("pune");
            break;
            
        }
        cout<<"DO U WANNA KNOW"<<endl;
        cin>>ch;
    }

    return 0;
}
