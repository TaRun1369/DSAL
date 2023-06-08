#include<iostream>
using namespace std;

class Node{
  string word;
  string meaning;
  Node* left;
  Node* right;
  friend class BST;
  
  public:
  Node(){
      word = "";
      meaning = "";
      left = NULL;
      right = NULL;
      
  }
  
  Node(string w,string m){
      word = w;
      meaning = m;
      left = NULL;
      right = NULL;
      
  }
};

class BST{
  public:
    Node* root;

  BST(){
      root = NULL;
  }
  Node* insertNode(Node* r,string data,string meaning){
      if(r == NULL){
          Node* newNode = new Node(data,meaning);
          return newNode;
      }
      else if(r->word > data){
          r->left = insertNode(r->left,data,meaning);
      }
      else if(r->word < data){
          r->right = insertNode(r->right,data,meaning);
      }
      return r;
  }
  
  void InorderAsc(Node* r){
      if(r == NULL) return;
      
      InorderAsc(r->left);
      cout<<r->word<<"->"<<r->meaning<<endl;
      InorderAsc(r->right);
  }
  void InorderDes(Node* r){
      if(r == NULL) return;
      
      InorderDes(r->right);
      cout<<r->word<<" "<<r->meaning<<endl;
      InorderDes(r->left);
  }
  
  void Search(Node* r,string key){
      if(r == NULL ) return;
      if(r->word == key){
          cout<<"Found"<<endl;
          return;
      }
      else if(r->word > key){
           Search(r->left,key);
      }
      else if(r->word < key){
           Search(r->right,key);
      }
      return;
      
      
  }
  
  Node* deleteNode(Node* r,string wo){
      if(r == NULL) return NULL;
    //  if(r->word == wo){
    //      Node*  temp  = r;
    //      delete temp;
    //      return NULL;
    //  }
     else if(r->word > wo){
         r->left = deleteNode(r->left,wo);
     }
     else if(r->word < wo){
         r->right = deleteNode(r->right,wo);
     }
     
     else{
         if(r->left == NULL && r->right == NULL){
             Node*  temp = r;
             delete r;
             return NULL;
         }
         else if(r->left != NULL && r->right == NULL){
             return r->left;
         }
          else if(r->left == NULL && r->right != NULL){
             return r->right;
         }
         else{
             Node*  temp = r->left;
             while(temp->right){
                 temp = temp->right;
             }
             string d = r->word;
             r->word = temp->word;
             temp->word = d;
             r->left = deleteNode(r->left,wo);
         }
         
     }
     return r;
  }
  
};

int main(){
    
    BST t;
    t.root = t.insertNode(t.root,"123","4567");
        t.root = t.insertNode(t.root,"ekdoteen","chaarpachsehsaat");

    t.root = t.insertNode(t.root,"891011","1213");

    t.root = t.insertNode(t.root,"terakaru","gin gin gin intezar");
    
     t.InorderAsc(t.root);
     cout<<endl;
     t.InorderDes(t.root);
     
     t.Search(t.root,"123");
     cout<<endl;
     t.root = t.deleteNode(t.root,"891011");
     
          t.InorderAsc(t.root);

     

}