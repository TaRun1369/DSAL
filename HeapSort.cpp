/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class heap{
    int * heapArr;
    int n = 0;
  public:
  heap(){
      cout<<"Enter n - number of  elements"<<endl;
      cin>>n;
      heapArr = new int[n];
      for(int i = 0;i<n;i++){
          heapArr[i] = 0;
      }
  }
  
  void create(){
      int root,left,right;
      cout<<"Enter the value of root"<<endl;
      cin>>root;
      heapArr[0] = root;
    for(int i = 0;i<n/2 ;i++){
        cout<<"Enter the left element of "<<heapArr[i]<<" : "<<endl;
        cin>>left;
        heapArr[2*i+1] = left;
        cout<<"Enter the right element of "<<heapArr[i]<<" : "<<endl;
        cin>>right;
        heapArr[2*i+2] = right;
    }

  }
  
  void maxHeap(){
      int startingIndex = n/2 -1;
      for(int i = startingIndex;i>=0;i--){
          HeapCreator(heapArr,n,i);
      }
  }
  
  void HeapCreator(int arr[],int n ,int i){
      int largest = i;
      int l = 2*i+1;
      int r= 2*i +2;
      
      if(l < n && arr[l] > arr[largest]){
          largest = l;
      }
      if(r < n && arr[r] > arr[largest]){
          largest = r;// now if above true largest is set to l
      }
      if(largest != i){
          swap(arr[i],arr[largest]);
          HeapCreator(heapArr,n,largest);
      }
  }
  
  void display(){
      for(int i = 0;i<n;i++){
          cout<<heapArr[i]<<" ";
      }
  }
  
  void swap(int &a,int &b){
      int t = a;
      a = b;
      b = t;
  }
  
  void heapSort(){
      for(int i = n/2 -1 ;i>=0;i--){
          HeapCreator(heapArr,n,i);
      }
      
      for(int i = n-1;i>=0;i--){
          swap(heapArr[0],heapArr[i]);
          HeapCreator(heapArr,i,0);
      }
  }
  
  void HeapCreator1(int arr[],int n ,int i){
      int smallest = i;
      int l = 2*i+1;
      int r= 2*i +2;
      
      if(l < n && arr[l] < arr[smallest]){
          smallest = l;
      }
      if(r < n && arr[r] < arr[smallest]){
          smallest = r;// now if above true smallest is set to l
      }
      if(smallest!= i){
          swap(arr[i],arr[smallest]);
          HeapCreator(heapArr,n,smallest);
      }
  }
  
  void insert(){
      int key;
      cout<<"Enter the new element"<<endl;
      cin>>key;
      n++;
      heapArr[n-1] = key;
      
      for(int i = n/2 -1;i>=0;i--){
          HeapCreator(heapArr,n,i);
      }
      
  }
  
  void deletee(){
     swap(heapArr[0],heapArr[n-1]);
     
     n--;
         HeapCreator(heapArr,n,0);
     
     
  }
  
  
};

int main()
{
    heap h;
    h.create();
    h.display();
    cout<<endl;
    h.maxHeap();
    
    h.display();
    cout<<endl;
    h.heapSort();
    
    h.display();
    cout<<endl;
    
    h.insert();
    h.display();
    cout<<endl;
    
    h.deletee();
    h.display();
    cout<<endl;
}
