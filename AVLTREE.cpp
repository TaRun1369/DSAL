/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class AVLNode{
    int data,ht;
    AVLNode* left,*right;
    
    public:
    AVLNode(int d){
        data = d;
        left = NULL;
        right = NULL;
        ht = 1;
        
    }
    friend class AVLTree;
};

class AVLTree{
    AVLNode* root;
    public:
    AVLTree(){
    root = NULL;
    }
    
    int height(AVLNode* rt){
        if(rt == NULL){
            return 0;
        }
        return rt->ht;
    }
    
    AVLNode* getter(){
        return root;
    }
    
    void setter(AVLNode* rt){
        root = rt;
    }
    
    int balancefactor(AVLNode* rt){
        if(rt == NULL){
            return 0;
        }
        return height(rt->left) - height(rt->right);
    }
    
    AVLNode* insert(AVLNode* rt,int data){
        if(rt == NULL){
            AVLNode* nN = new AVLNode(data);
            
            return nN;
        }
        
        if(data>rt->data){
            rt->right = insert(rt->right,data);
            
        }
        if(data<rt->data){
            rt->left = insert(rt->left,data);
            
        }
        
        rt->ht = max(height(rt->left),height(rt->right)) + 1;
        rt = balance(rt,data);
        return rt;
    }
    
    AVLNode* leftRotate(AVLNode* rt){
        AVLNode* x,*y;
        x = rt->right;
        y = x->left;
        
        x->left = rt;
        rt->right = y;
        
        rt->ht = max(height(rt->left),height(rt->right)) + 1;
                x->ht = max(height(x->left),height(x->right)) + 1;
        return x;
    }
    
    int max(int a,int b){
        return a > b ? a : b;
    }
    
    AVLNode* RightRotate(AVLNode* rt){
        AVLNode* x,*y;
        x = rt->left;
        y = x->right;
        
        x->right = rt;
        rt->left = y;
        
        rt->ht = max(height(rt->left),height(rt->right)) + 1;
        x->ht = max(height(x->left),height(x->right)) + 1;
        return x;
    }
    
    AVLNode* balance(AVLNode* &rt,  int data){
        int bf = balancefactor(rt);
        
        if(bf > 1 && data < rt->left->data){
            // RightRotate
            return RightRotate(rt);
        }
        if(bf >1 && data > rt->left->data){
            rt->left = leftRotate(rt->left);
            return RightRotate(rt);
        }
        if(bf < -1 && data > rt->right->data){
            return leftRotate(rt);
        }
        if(bf < -1 && data < rt->right->data){
            rt->right = RightRotate(rt->right);
            return leftRotate(rt);
        }
        
     
        return rt;
    }
    
    void Inorder(AVLNode* rt){
        if(rt != NULL){
            Inorder(rt->left);
            cout<<rt->data<<" ";
            Inorder(rt->right);
        }
    }
    
    
    
    
};



int main()
{
    AVLTree t;
    // 10 20 30 40 50 25
    // Inorder - 10 20 25 30 40 50
    
    
    int Ar[6] = {10 ,20 ,30 ,40 ,50 ,25};
    AVLNode* root = NULL;
    for(int i = 0;i<6;i++){
        cout<<"Element inserted : "<<Ar[i]<<endl;
         root = t.insert(t.getter(),Ar[i]);
        t.setter(root);
        
        
    }
    
    t.Inorder(root);
    return 0;
}
