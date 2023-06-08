/******************************************************************************

                              Online C++ Compiler.
              Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Edge{
    public:
  int src;
  int des;
  int weight;
};

class Graph{
  int nv;
  int ed;
  int ** adjMat;
  public:
  Graph(int v,int d){
      nv = v;
      ed = d;
      adjMat = new int*[nv];
      for(int i = 0;i<nv;i++){
          adjMat[i] = new int[nv]; 
      }
  }
  
  void initialize(){
      for(int i= 0;i<nv;i++){
          for(int j = 0;j<nv;j++){
              adjMat[i][j]  = 0;
          }
      }
      
      for(int x = 0;x<ed;x++){
          int sr,de,wt;
          cout<<"Enter Source"<<endl;
          cin>>sr;
          cout<<"Enter destination"<<endl;
          cin>>de;
          cout<<"Enter weight"<<endl;
          cin>>wt;
          adjMat[sr][de] = wt;
          adjMat[de][sr] = wt;
          
      }
  }


  void prims(int start){
        int reach[nv];
        int unreach[nv];
        int result[nv][nv];
        
        for(int i = 0;i <nv;i++){
            for(int j  = 0;j<nv;j++){
            result[i][j]  = 0;
            }
        }
        
        
        for(int i  = 0;i<nv;i++){
            reach[i] = 0;
            unreach[i] = 1;
            
        }
        
        int edge = 0;
        int weight = 0;
        reach[start] = 1;
        unreach[start] = 0;
        cout<<"Path"<<"\t"<<"cost"<<endl;
        while(edge < nv-1){
            int s = 100000;
            int flag = 0;
            int a = 0,b = 0;
            for(int i = 0;i<nv;i++){
            if(reach[i] == 1){
                for(int j = 0;j<nv;j++){
                    if(unreach[j] == 1){
                        if(s>adjMat[i][j] && adjMat[i][j] != 0){
                            flag =1;
                            s = adjMat[i][j];
                            a = i;b=j;
                            
                        }
                    }
                }
            }
        }
        
        if(flag == 1){
            weight+=s;
            reach[b] = 1;
            unreach[b] =0;
            edge++;
            result[a][b] = s;
        }
        
        }
        
        for(int i = 0;i<nv;i++){
            
            for(int j = 0;j<nv;j++){
                if(result[i][j]!=0)
                cout<<i<<"-"<<j<<"\t"<<result[i][j]<<endl;
            }
        }
        
        cout<<"D=================================================D"<<endl;
    }  
  
  void k(){
      Edge *e = new Edge[ed];
      
      int vis[nv][nv];
      for(int i = 0;i<nv;i++){
          for(int j = 0;j<nv;j++){
              vis[i][j] = 0;
          }
      }
      
      for(int x = 0;x<ed;x++){
          int mini = 1000000;
          int a,b;
          
          for(int i = 0;i<nv;i++){
              for(int j = 0;j<nv;j++){
                  if(vis[i][j] == 0 && vis[j][i] == 0 && adjMat[i][j] < mini && adjMat[i][j] != 0 ){
                      a = i;b = j;
                      mini= adjMat[a][b];
                  }
              }
          }
          
          vis[a][b] = 1;
          
          e[x].src = a;
          e[x].des = b;
          e[x].weight = mini;
      }
      
      
      int vi[nv];
      // mst ke liye visited vertices ka array
      for(int i=0;i<nv;i++)vi[i] = 0;
      
      
      int result[nv][nv];
      
      for(int i = 0;i<nv;i++){
          for(int j = 0;j<nv;j++){
              result[i][j] = 0;
          }
      }
      
      
      
      for(int x = 0;x<ed;x++){
          if(vi[e[x].src] == 0 || vi[e[x].des] == 0){
              result[e[x].src][e[x].des] = e[x].weight;
              vi[e[x].src] = 1;
              vi[e[x].des] = 1;
          }
      }
      
      int weigh = 0;
      
      for(int i = 0;i<nv;i++){
          for(int j = 0;j<nv;j++){
              if(result[i][j] != 0){
                  weigh += result[i][j];
                  cout<<i<<" - "<<j<<" weight - "<<result[i][j]<<endl;
              }
          }
      }
      
      cout<<"Min wight"<<endl;
      cout<<weigh<<endl;
      
  }
  
};


int main()
{
    int nv,ed;
    cout<<"Enter NUmber of Vertices:";
    cin>>nv;
    cout<<"Enter NUmber of Edges:";
    cin>>ed;
    Graph g(nv,ed);
    g.initialize();
    // g.display();
    g.prims(0);

    g.k();

    return 0;
}
