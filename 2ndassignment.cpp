#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node {
    int data;
    Node *lchild;
    Node *rchild;

public:
    Node(){
        data = 0;
        lchild = rchild = NULL;
    }
    Node(int x) {
        data = x;
        lchild = NULL;
        rchild = NULL;
    }
    friend class BinaryTree;
};

class BinaryTree {
    Node *root;

public:
    BinaryTree(){
        root = NULL;
    }
    void setRoot(Node* temp) {
        root = temp;
    }
    Node* getRoot() {
        return root;
    }
    
    void preOrder(Node *temp) {
        if (temp != NULL) {
            cout << temp->data << "\t";
            preOrder(temp->lchild);
            preOrder(temp->rchild);
        }
    }
    void preOrderIterative() {
        stack<Node*> s;
        Node *temp = root;
        s.push(temp);
        while (!s.empty()) {
            Node *t = s.top();
            s.pop();
            cout << t->data << "\t";
            if (t->rchild != NULL) {
                s.push(t->rchild);
            }
            if (t->lchild != NULL) {
                s.push(t->lchild);
            }
        }
    }
    void postOrder(Node *temp) {
        if (temp != NULL) {
            postOrder(temp->lchild);
            postOrder(temp->rchild);
            cout << temp->data << "\t";
        }
    }
    void postOrderIterative() {
        stack<Node*> s1;
        stack<Node*> s2;
        Node *temp = root;
        s1.push(temp);
        while (!s1.empty()) {
            Node *t = s1.top();
            s1.pop();
            s2.push(t);
            if (t->lchild != NULL) {
                s1.push(t->lchild);
            }
            if (t->rchild != NULL) {
                s1.push(t->rchild);
            }
        }
        while (!s2.empty()) {
            Node *t = s2.top();
            s2.pop();
            cout << t->data << "\t";
        }
    }
    void inOrder(Node *temp) {
        if (temp != NULL) {
            inOrder(temp->lchild);
            cout << temp->data << "\t";
            inOrder(temp->rchild);
        }
    }
    void inOrderIterative() {
        stack<Node*> s;
        Node *temp = root;
        while (!s.empty() || temp != NULL) {
            while (temp != NULL) {
                s.push(temp);
                temp = temp->lchild;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << "\t";
            temp = temp->rchild;
        }
    }
    void recurssiveCreation() {
        int temp;
        cout << "Enter the root:->" << endl;

        cin >> temp;
        root = new Node(temp);
        creator(root);
    }
    
    void creator(Node *temp) {
        int x;
        cout << "Enter the left child of " << temp->data<< "\n enter -1 to quit" << endl;
        cin >> x;
        if (x != -1) {
            Node *newN = new Node(x);
            temp->lchild = newN;
            creator(newN);
        }
        cout << "Enter the right child of " << temp->data
                << "\n enter -1 to quit" << endl;
        cin >> x;
        if (x != -1) {
            Node *newN = new Node(x);
            temp->rchild = newN;
            creator(newN);
        }
    }

    void createBinaryTree() {
        int x;
        queue<Node*> q;
        if (root == NULL) {
            cout << "Enter the root data: ";
            cin >> x;
            root = new Node(x);
            q.push(root);
        }
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            cout
                    << "Enter the left child of:- \n (If left child not exist,Enter -1): "
                    << temp->data << endl;
            cin >> x;
            if (x != -1) {
                temp->lchild = new Node(x);
                q.push(temp->lchild);
            }
            cout
                    << "Enter the right child:- \n (If right child not exist,Enter -1): "
                    << temp->data << endl;
            cin >> x;
            if (x != -1) {
                temp->rchild = new Node(x);
                q.push(temp->rchild);
            }
        }
    }
    
    void mirror(Node *temp) {
        if (temp == NULL) {
            return;
        } 
        else {
            Node *newN = new Node();
            mirror(temp->lchild);
            mirror(temp->rchild);
            newN = temp->lchild;
            temp->lchild = temp->rchild;
            temp->rchild = newN;
        }
    }
    
    void operator =(BinaryTree &t1) {
        root = copyTree(t1.getRoot());
    }
    
    Node* copyTree(Node *temp) {
        Node *cp = NULL;
        if (temp != NULL) {
            cp = new Node(temp->data);
            cp->lchild = copyTree(temp->lchild);
            cp->rchild = copyTree(temp->rchild);
        }
        return cp;
    }
    
    int treeHeight(Node *temp) {
        if (temp == NULL) {
            return -1;
        } 
        else {
            int lheight = treeHeight(temp->lchild);
            int rheight = treeHeight(temp->rchild);
            if (lheight > rheight) {
                return lheight + 1;
            } else {
                return rheight + 1;
            }
        }
    }
   
    void deleteTree(Node *temp) {
        if (temp == NULL) {
            return;
        }
        deleteTree(temp->lchild);
        deleteTree(temp->rchild);
        delete temp;
    }
    
    void inOrder2(Node *temp, int &cnt) {
        if (temp == NULL) {
            return;
        }
        inOrder2(temp->lchild, cnt);
        if (temp->lchild == NULL && temp->rchild == NULL) {
            cnt++;
        }
        inOrder2(temp->rchild, cnt);
    }
    
    int leafCount(Node *temp) {
        int cnt = 0;
        inOrder2(temp, cnt);
        return cnt;
    }
    void inOrder3(Node *temp, int &cnt) {
        if (temp == NULL) {
            return;
        }
        inOrder3(temp->lchild, cnt);
        if (temp->lchild != NULL || temp->rchild != NULL) {
            cnt++;
        }
        inOrder3(temp->rchild, cnt);
    }
    int internalNodeCount(Node *temp) {
        int cnt = 0;
        inOrder3(temp, cnt);
        return cnt;
    }
};
int main() {
    BinaryTree a;
    BinaryTree b;
    a.createBinaryTree();
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
            a.inOrderIterative();
            cout << "\n";
            cout << "Preorder iterative : " << endl;
            a.preOrderIterative();
            cout << "\n";
            cout << "Postorder iterative : " << endl;
            a.postOrderIterative();
            cout << "\n";
            break;
        case 2:
            cout << "Mirror image" << endl;
            a.mirror(a.getRoot());
            cout << "Inorder : " << endl;
            a.inOrder(a.getRoot());
            break;
        case 3:
            cout << "Height of Tree is:" << endl;
            cout << a.treeHeight(a.getRoot());
            cout << "\n";
            break;
        case 4:
            cout << "Number of leaves:" << endl;
            cout << a.leafCount(a.getRoot());
            cout << "\n";
            break;
        case 5:
            cout << "Number of internal Nodes:" << endl;
            cout << a.internalNodeCount(a.getRoot());
            cout << "\n";
            break;
        case 6:
            b = a;
            cout << "Inorder of a:" << endl;
            a.inOrder(a.getRoot());
            cout << "\n";
            cout << "Inorder of b:" << endl;
            b.inOrder(b.getRoot());
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
            a.inOrder(a.getRoot());
            cout << "\n";
            cout << "Preorder recursive : " << endl;
            a.preOrder(a.getRoot());
            cout << "\n";
            cout << "Postorder recursive : " << endl;
            a.postOrder(a.getRoot());
            cout << "\n";

            break;
        case 2:
            cout << "Mirror image" << endl;
            a.mirror(a.getRoot());
            cout << "Inorder : " << endl;
            a.inOrder(a.getRoot());
            break;
        case 3:
            cout << "Height of Tree is:" << endl;
            cout << a.treeHeight(a.getRoot());
            cout << "\n";
            break;
        case 4:
            cout << "Number of leaves:" << endl;
            cout << a.leafCount(a.getRoot());
            cout << "\n";
            break;
        case 5:
            cout << "Number of internal Nodes:" << endl;
            cout << a.internalNodeCount(a.getRoot());
            cout << "\n";
            break;
        case 6:
            b = a;
            cout << "Inorder of a:" << endl;
            a.inOrder(a.getRoot());
            cout << "\n";
            cout << "Inorder of b:" << endl;
            b.inOrder(b.getRoot());
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