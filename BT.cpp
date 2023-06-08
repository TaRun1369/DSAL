#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
  int data;
  Node* lchild,*rchild;
  public:
  Node(int d = 0){
      data = d;
      lchild = NULL;
      rchild = NULL;
  }
  friend class BT;
};

class BT{
  Node* root;
  public:
  BT(){
      root = NULL;
  }
  void setRoot(Node* t){
      root =t;
  }
  
  Node* getRoot(){
      return root;
  }
  // recursive preorder
  void preorder(Node* temp){
      if(temp != NULL){
          cout<<temp->data<<" ";
          preorder(temp->lchild);
          preorder(temp->rchild);
      }
  }
  
  //recursive inorder
  void inorder(Node* temp){
      if(temp!= NULL){
          inorder(temp->lchild);
          cout<<temp->data<<" ";
          inorder(temp->rchild);
      }
  }
  
  // recursive postorder
  void postorder(Node* temp){
      if(temp!= NULL){
          postorder(temp->lchild);
          postorder(temp->rchild);
          cout<<temp->data<<endl;
      }
  }
  
  // preorder iterative
  void preorderiterative(){
      if(root == NULL){
          return;
      }
      Node* temp = root;
      stack<Node*> s;
      s.push(temp);
      while(!s.empty()){
          Node* t = s.top();
          s.pop();
          cout<<t->data<<" ";
          if(t->rchild != NULL){
              s.push(t->rchild);
          }
          if(t->lchild != NULL){
              s.push(t->lchild);
          }
          
      }
  }
  
   // inorder iterative
    void inorderiterative(){
        
        Node* temp = root;
        stack<Node*> s;
        while(!s.empty() || temp!= NULL){
            while(temp != NULL){
                s.push(temp);
                temp = temp->lchild;
            }
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp = temp->rchild;
        }
    }  
    
    
    void postorderiterative(){
        Node* temp = root;
        stack<Node*> s1,s2;
        s1.push(temp);
        while(!s1.empty()){
            Node* t = s1.top();
            s1.pop();
            s2.push(t);
            
            if(t->lchild != NULL){
                s1.push(t->lchild);
            }
            if(t->rchild != NULL){
                s1.push(t->rchild);
            }
        }
        
        while(!s2.empty()){
            Node* temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
        }
    }
    
    void recursiveCreator(){
        int x;
        cout<<"Enter root ka data"<<endl;
        cin>>x;
        root = new Node(x);
        creator(root);
    }
    
    void creator(Node* root){
        
        int x;
        cout<<"Enter value of left child of "<<root->data<<"(if doesnt exist put -1)"<<endl;
        cin>>x;
        if(x!= -1){
            root->lchild = new Node(x);
            creator(root->lchild);
        }
        int y;
        cout<<"Enter value of right child of "<<root->data<<"(if doesnt exist put -1)"<<endl;
        cin>>y;
        if(y!=-1){
            root->rchild = new Node(y);
            creator(root->rchild);
        }
    }
    
    void iterativecreator(){
        queue<Node*> q;
        if(root == NULL){
            int x;
            cout<<"Enter value of root of (if doesnt exist put -1)"<<endl;
            cin>>x;
            root = new Node(x);
            q.push(root);
        }
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            int x;
        cout<<"Enter value of left child of "<<temp->data<<"(if doesnt exist put -1)"<<endl;
        cin>>x;
        if(x!= -1){
            temp->lchild = new Node(x);
            q.push(temp->lchild);
        }
        int y;
        cout<<"Enter value of right child of "<<temp->data<<"(if doesnt exist put -1)"<<endl;
        cin>>y;
        if(y!=-1){
            temp->rchild = new Node(y);
            q.push(temp->rchild);
        }
            
        }
    }
    
    void operator =(BT &t1){
        root = copytree(t1.getRoot());
    }
    
    Node* copytree(Node* temp){
      Node* t = NULL;
        if(temp != NULL){
             t  = new Node(temp->data);
            t->lchild = copytree(temp->lchild);
            t->rchild = copytree(temp->rchild);
        }
        return t;
    }
    
    void mirror(Node* temp){
        if(temp ==  NULL){
            return;
          
            
        }
        else{
            Node* nN = new Node();
            mirror(temp->lchild);
            mirror(temp->rchild);
            nN = temp->lchild;
            temp->lchild = temp->rchild;
            temp->rchild = nN;
           
        }
        
    }
    
    int height(Node* temp){
        if(temp == NULL){
            return 0;
        }
        int lh = height(temp->lchild);
        int rh = height(temp->rchild);
        
        if(lh > rh){
            return lh + 1;
        }
        else{
            return rh + 1;
        }
    }
    
    void deleteTree(Node* temp){
        if(temp != NULL){
            deleteTree(temp->lchild);
            deleteTree(temp->rchild);
            delete temp;
        }
    }
    
    
    
  
};



int main() {
    BT a;
    BT b;
    a.iterativecreator();
    int ch, flag = 1;
    int flag2 = 1;
    int flag3 = 1;
    int choice;
    while(flag2)
    {   
        cout << "Select method of Traversal: " <<endl;
        cout << "1.Iterative : " << endl;
        cout << "2.Recursive : " << endl;
        cout << "Enter your choice: " <<endl;
        cin >> choice;
        switch (choice){
    case 1:
    while (flag == 1){
        cout << " Operations : " << endl;
        cout << "1. Inorder, Preorder and Postorder" << endl;
        cout << "2. Mirror Image" << endl;
        cout << "3. Height of the tree" << endl;
        cout << "4. Number of leaves" << endl;
        cout << "5. Number of Internal Nodes" << endl;
        cout << "6. Copy tree" << endl;
        cout << "7. Delete all nodes" << endl;
        cout << "8.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Inorder iterative : " << endl;
            a.inorderiterative();
            cout << "\n";
            cout << "Preorder iterative : " << endl;
            a.preorderiterative();
            cout << "\n";
            cout << "Postorder iterative : " << endl;
            a.postorderiterative();
            cout << "\n";
            break;
        case 2:
            cout << "Mirror image" << endl;
            a.mirror(a.getRoot());
            cout << "Inorder : " << endl;
            a.inorder(a.getRoot());
            break;
        case 3:
            cout << "Height of Tree is:" << endl;
            cout << a.height(a.getRoot());
            cout << "\n";
            break;
        case 4:
            cout << "Number of leaves:" << endl;
            // cout << a.leafCount(a.getRoot());
            cout << "\n";
            break;
        case 5:
            cout << "Number of internal Nodes:" << endl;
            // cout << a.internalNodeCount(a.getRoot());
            cout << "\n";
            break;
        case 6:
            b = a;
            cout << "Inorder of a:" << endl;
            a.inorder(a.getRoot());
            cout << "\n";
            cout << "Inorder of b:" << endl;
            b.inorder(b.getRoot());
            cout << "\n";
            break;
        case 7:
            a.deleteTree(a.getRoot());
            a.setRoot(NULL);
            break;
            case 8:
            break;
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
        cout << "Do you want to continue?(1 for yes/0 for no):" << endl;
        cin >> flag;
    }
    break; 

case 2:
     while (flag3 == 1){
        cout << " Operations : " << endl;
        cout << "1. Inorder, Preorder and Postorder" << endl;
        cout << "2. Mirror Image" << endl;
        cout << "3. Height of the tree" << endl;
        cout << "4. Number of leaves" << endl;
        cout << "5. Number of Internal Nodes" << endl;
        cout << "6. Copy tree" << endl;
        cout << "7. Delete all nodes" << endl;
        cout << "8.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Inorder recursive : " << endl;
            a.inorder(a.getRoot());
            cout << "\n";
            cout << "Preorder recursive : " << endl;
            a.preorder(a.getRoot());
            cout << "\n";
            cout << "Postorder recursive : " << endl;
            a.postorder(a.getRoot());
            cout << "\n";

            break;
        case 2:
            cout << "Mirror image" << endl;
            a.mirror(a.getRoot());
            cout << "Inorder : " << endl;
            a.inorder(a.getRoot());
            break;
        case 3:
            cout << "Height of Tree is:" << endl;
            cout << a.height(a.getRoot());
            cout << "\n";
            break;
        case 4:
            cout << "Number of leaves:" << endl;
            // cout << a.leafCount(a.getRoot());
            cout << "\n";
            break;
        case 5:
            cout << "Number of internal Nodes:" << endl;
            // cout << a.internalNodeCount(a.getRoot());
            cout << "\n";
            break;
        case 6:
            b = a;
            cout << "Inorder of a:" << endl;
            a.inorder(a.getRoot());
            cout << "\n";
            cout << "Inorder of b:" << endl;
            b.inorder(b.getRoot());
            cout << "\n";
            break;
        case 7:
            a.deleteTree(a.getRoot());
            a.setRoot(NULL);
            break;
            case 8:
            break;
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
        cout << "Do you want to continue?(1 for yes/0 for no):" << endl;
        cin >> flag3;
    }
    break;  
    }
    cout << "Do you want to continue for method of traversal?(1 for yes/0 for no):" << endl;
    cin >> flag2;
    }
    return 0;
}


