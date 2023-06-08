#include<iostream>
using namespace std;

class Node{
  int data;
  Node* lc,*rc;
  bool lt,rt;
  public:
  Node(int d = -1){
      this->data = d;
      this->lc = NULL;
      this->rc = NULL;
      this->lt = 0;
      this->rt = 0;
  }
  friend class TBST;
};

class TBST{
    Node* root,*header;
    
    Node* search(Node* &parent,Node* &current,int key){
        while(current != header){
            if(current->data == key){
                return current;
            }
            else if(key < current->data){
                parent = current;
                current = current->lc;
            }
            else if(key > current->data){
                parent = current;
                current->rc;
            }
        }
        return NULL;
    }
    public:
    TBST(){
        header = new Node(-1);
        // header->rc = header;
        // header->lt = 1;
        // header->rt = 1;
        root = NULL;
        
    }
    
    Node* getroot(){
        return this->root;
    }
    
    void insert(int data){
        if(root == NULL){
            root = new Node(data);
            header->lc = root;
            header->lt = 1;
            root->lc = header;
            root->rc = header;
            
        }
        else{
            Node* parent = root;
            
            while(true){
                if(data < parent->data){
                    if(parent->lt == 1){
                          parent = parent->lc;
                    }
                    else{
                        Node* nN = new Node(data);
                        nN->lc = parent->lc;
                        parent->lc = nN;
                        nN->rc = parent;
                        parent->lt = 1;
                        break;
                    }
                }
                else if(data > parent->data) {
                    if(parent->rt == 1){
                        parent = parent->rc;
                    }
                    else
                    {
                        Node* nN = new Node(data);
                        nN->rc = parent->rc;
                        parent->rc = nN;
                        nN->lc = parent;
                        parent->rt = 1;
                        break;
                    }
                }
            }
            
        }
        
    }
    
    void Inorder(){
        Node* temp = root;
        
            while(temp->lt == 1){
                temp = temp->lc;// left most tak jayega
            }
            
            
            while(temp != header){
                
            cout<<temp->data<<" "; 
            
            if( temp->rt == 1){
                temp = temp->rc; // agar rightchild hai toh uspe jaake left most dhundhega
            
            
            while(temp->lt == 1){
                temp = temp->lc;
            }
            }
            else{
                temp = temp->rc; // nhi toh rc pe jayega matlab thread jaha leke jaa raha waha
            }
            
            
        }
    }
    
    void preorder(){
        Node* temp = root;
        
        while(temp!=header){
            cout<<temp->data<<" ";
            
            if(temp->lt == 1) temp = temp->lc;
            else if (temp->rt == 1 ) temp = temp->rc;
            else{
                while(temp != header && temp->rt == 0){ // yaha wapas jaa raha wo upar 
                // agar left side raha toh tab tak jayega jab tak upar wale kisike pass right child nhi hota 
                // agar right side mein hai toh sidha header pe jayega bcoz left wla pehle he ho gaya hai chutiye/\.........
                    temp = temp->rc;
                }
                if(temp != header){ // har jaghah check temp != header
                    temp = temp->rc;
                }
            }
        }
    }
    
    
     void preOrder(Node *temp)
    {
        while (temp != header)
        {
            cout << temp->data << " ";
            if (temp->lt == 1)
            {
                temp = temp->lc;
            }
            else if (temp->rt == 1)
            {
                temp = temp->rc;
            }
            else
            {
                while (temp != header && temp->rt == 0)
                {
                    temp = temp->rc;
                }
                if (temp != header)
                {
                    temp = temp->rc;
                }
            }
        }
    }
    
    void deletion(int key){
        Node* parent = NULL;
        Node* current = root;
        if(search(parent,current,key) == NULL){
            cout<<"chutiya bana rahe ho koi hai he nhi"<<endl;
            return;
        }
        else{
            // case of two child
            
            if(current->lt == 1 && current->rt == 1){
                Node* c = current->rc;
                Node* cs = current;
                while(c->lt != 0){
                    cs= c;
                    c = c->lc;
                    
                }
                current->data = c->data;
                current = c;
                parent = cs;
                
            }
            
            // case of no child
            if(current->lt == 0 && current->rt == 0){
                if(current == parent->lc){
                parent->lc = current->lc;
                parent->lt = 0;
                }
                if(current == parent->rc){
                    parent->rc = current->rc;
                    parent->rt = 0;
                }
                delete current;
            }
            // case of left child
            if(current->lt == 1 && current->rt == 0){
                Node* child = current->lc;
                Node* temp = child;
                while(temp->rt != 0){
                    temp = temp->rc;
                }
                temp->rt = current->rt;
                temp -> rc = current;
                if(parent->lc == current){
                    parent->lc = child;
                }
                else{
                    parent->rc = child;
                }
                delete current;
            }
            
            //case of right child 
            if(current->rt == 1 && current->lt == 0){
                Node* child = current->rc;
                Node* temp = child;
                while(temp->lt != 0){
                    temp = temp->lc;
                }
                temp->lt = current->lt;
                temp->lc = current;
                if(parent->lc == current){
                    parent->lc = child;
                }
                else{
                    parent->rc = child;
                }
                delete current;
                
            }
        }
    }
};



int main(){
    TBST tbst;
       
    tbst.insert(15);
    tbst.insert(10);
    tbst.insert(17);
    tbst.insert(6);
    tbst.insert(12);
    tbst.insert(11);
    tbst.insert(13);
    
    tbst.Inorder();
    cout<<endl;
    
    tbst.deletion(10);
    
    tbst.Inorder();
    cout<<endl;

}