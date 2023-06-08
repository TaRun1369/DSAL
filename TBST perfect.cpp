#include<iostream>
using namespace std;

class Node{

    private:
    int data;
    Node *lc, *rc;
    bool lf, rf;

    public:
    Node(int data=-1){
        this->data = data;
        this->lc = NULL;
        this->rc = NULL;
        this->lf = 0;
        this->rf = 0;
    }

    friend class TBST;
};


class TBST{

    private:
    Node *root, *header;

    Node* search(Node* &parent, Node* &current, int key){
        
        while(current!=header){
            if(current->data == key){
                return current;
            }
            else if(current->data < key){
                parent = current;
                current = current->rc;
            }
            else{
                parent=current;
                current = current->lc;
            }
        }
        return NULL;
    }

    public:
    
    TBST(){
        root = NULL;
        header = new Node(-1);
    }


    Node* getRoot(){
        return this->root;
    }


    void insert(int data){

        if(root == NULL){
            root = new Node(data);
            root->lc = header;
            root->rc = header;
            header->lc = root;
            header->lf = 1;
        }else{

            Node *parent = root;

            while(true){

                if(data < parent->data){

                    if(parent->lf == 1){
                        parent = parent->lc;
                    }else{
                        Node *newNode = new Node(data);
                        newNode->lc = parent->lc;
                        newNode->rc = parent;
                        parent->lc = newNode;
                        parent->lf = 1;
                        break;
                    }

                }else if(data > parent->data){

                    if(parent->rf == 1){
                        parent = parent->rc;
                    }else{
                        Node *newNode = new Node(data);
                        newNode->rc = parent->rc;
                        newNode->lc = parent;
                        parent->rc = newNode;
                        parent->rf = 1;
                        break;
                    }

                }

            }

        }

    }


    void deleteN(int key){

        Node *parent = NULL;
        Node *current = root;

        if(search(parent, current, key) == NULL ){
            cout<<"Key not found"<<endl;
        }else{

            // 2 child case
            if(current->lf == 1 && current->rf == 1){
                Node *c = current->rc;
                Node *cs = current;
                while(c->lf != 0){
                    cs = c;
                    c = c->lc;
                }
                current->data = c->data;
                current = c;
                parent = cs;
            }

            // no child case
            if(current->lf == 0 && current->rf == 0){
                if(parent->lc == current){
                    parent->lf = current->lf;
                    parent->lc = current->lc;
                }
                else if(parent->rc == current){
                    parent->rf = current->rf;
                    parent->rc = current->rc;
                }
                delete current;
            }

            // left child case
            if(current->lf == 1 && current->rf == 0){
                Node *child = current->lc;
                Node *t = child;
                while(t->rf != 0){
                    t = t->rc;
                }
                t->rf = current->rf;
                t->rc = current->rc;
                parent->lc = child;
                delete current;
            }

            // right node case
            if(current->rf == 1 && current->lf == 0){
                Node *child = current->rc;
                Node *t = child;
                while(t->lf != 0){
                    t->lf = current->lf;
                    t->lc = current->lc;
                    parent->rc = child;
                    delete current;
                }
            }

        }

    }


    void inOrder(Node *temp)
    {

        while (temp->lf == 1)
        {
            temp = temp->lc;
        }
        while (temp != header)
        {
            cout << temp->data << " ";

            if (temp->rf == 1)
            {
                temp = temp->rc;
                while (temp->lf == 1)
                {
                    temp = temp->lc;
                }
            }
            else
            {
                temp = temp->rc;
            }
        }
    }
    
    
    void preOrder(Node *temp)
    {
        while (temp != header)
        {
            cout << temp->data << " ";
            if (temp->lf == 1)
            {
                temp = temp->lc;
            }
            else if (temp->rf == 1)
            {
                temp = temp->rc;
            }
            else
            {
                while (temp != header && temp->rf == 0)
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

};

int main(){

    TBST tbst;
    
    tbst.insert(10);
    tbst.insert(5);
    tbst.insert(15);
    tbst.insert(3);
    tbst.insert(8);

    tbst.inOrder(tbst.getRoot());
    cout<<endl;

    tbst.deleteN(8);

    tbst.inOrder(tbst.getRoot());

    return 0;
}