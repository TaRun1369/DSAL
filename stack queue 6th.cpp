#include <iostream>
#include <queue>
#include <stack>
#define size 20
using namespace std;

template <class T>
class Stack
{
    T *arr;
    int top;
    template <class T1>
    friend class Graph;

public:
    Stack()
    {
        arr = new T[size];
        top = -1;
    }

    void push(T data)
    {
        if (top == size - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    T pop()
    {
        if (top != -1)
        {

            T data = arr[top];
            top--;
            return data;
        }
    }

    T peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

template <class T>
class Queue
{
    T *arr;
    int front;
    int rear;

    template <class T1>
    friend class Graph;

public:
    Queue()
    {
        arr = new T[size];
        front = -1;
        rear = -1;
    }

    void enqueue(T data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            arr[rear] = data;
        }
    }

    T dequeue()
    {
        if (!(front == -1 || front > rear))
        {
            T data = arr[front];
            front++;
            return data;
        }
    }

    T peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

template <class T>
class Node // for adjacency list representation using linked list
{
    T data;
    Node *next;
    int weight;

    template <class T1>
    friend class Graph;

public:
    Node()
    {
        // data = "";
        next = NULL;
        weight = 0;
    }
    Node(T data, int weight)
    {
        this->data = data;

        next = NULL;
    }
};

class Pair // for using in hashmap
{
    int index;
    string city;
    template <class T1>
    friend class Graph;
};

template <class T>
class Graph
{
    Node<T> **adj;
    string *p;
    int v;

public:
    Graph()
    {
        cout << "Enter number of cities(vertices): ";
        cin >> v;
        p = new string[v];
        cout << "Enter names of the cities: \n";
        string city;
        for (int i = 0; i < v; i++)
        {
            cout << "Enter city " << i + 1 << ": ";
            cin >> city;

            p[i] = city;
        }

        adj = new Node<T> *[v];
        for (int i = 0; i < v; i++)
            adj[i] = NULL;

        cout << "Enter Edges: \n";
        char ch = 'y';
        string v1, v2;
        int wt;
        while (ch == 'y')
        {
            cout << "Enter first city: ";
            cin >> v1;
            cout << "Enter second city: ";
            cin >> v2;
            cout << "Enter weight of edge between " << v1 << " and " << v2 << ": ";
            cin >> wt;
            Node<T> *newnode = new Node<T>(v2, wt);
            Node<T> *temp = adj[search(v1)];

            if (temp == NULL)
            {
                adj[search(v1)] = newnode;
            }
            else
            {
                while (temp->next)
                    temp = temp->next;
                temp->next = newnode;
            }
            cout << "Do you want to enter another edge: ";
            cin >> ch;
        }
    }
    int search(string s)
    {
        for (int i = 0; i < v; i++)
        {
            if (p[i] == s)
                return i;
        }
    }
    void show()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "city: " << p[i] << " -> ";
            Node<T> *temp = adj[i];
            while (temp)
            {
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void bfs(T source)
    {
        cout << "BFS Traversal is: ";
        int visited[v];
        for (int i = 0; i < v; i++)
            visited[i] = 0;

        queue<T> q;
        q.push(source);
        visited[search(source)] = 1;
        T temp;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            cout << temp << ", ";
            Node<T> *temp_list = adj[search(temp)];

            while (temp_list)
            {
                if (visited[search(temp_list->data)] != 1)
                {
                    visited[search(temp_list->data)] = 1;
                    q.push(temp_list->data);
                }
                temp_list = temp_list->next;
            }
        }
        cout << endl;
    }

    void dfs(T source)
    {
        cout << "DFS Traversal is: ";
        int visited[v];
        for (int i = 0; i < v; i++)
            visited[i] = 0;

        stack<T> s;
        s.push(source);
        visited[search(source)] = 1;
        T temp;

        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            cout << temp << ", ";
            Node<T> *temp_list = adj[search(temp)];

            while (temp_list)
            {
                if (visited[search(temp_list->data)] != 1)
                {
                    visited[search(temp_list->data)] = 1;
                    s.push(temp_list->data);
                }
                temp_list = temp_list->next;
            }
        }
        cout << endl;
    }

    void in_out_degree()
    {
        int outdegree;
        for (int i = 0; i < v; i++)
        {
            outdegree = 0;
            Node<T> *temp = adj[i];
            while (temp)
            {
                outdegree++;
                temp = temp->next;
            }
            cout << "Outdegree of vertex: " << p[i] << " is "
                 << outdegree << endl;
        }
        int indegree;
        for (int i = 0; i < v; i++)
        {
            indegree = 0;
            for (int j = 0; j < v; j++)
            {
                if (j != i)
                {
                    Node<T> *temp = adj[j];
                    while (temp)
                    {
                        if (temp->data == p[i])
                            indegree++;
                        temp = temp->next;
                    }
                }
            }
            cout << "Indegree of vertex: " << p[i] << " is "
                 << indegree << endl;
        }
    }

    bool isConnected()
    {
        int connectivity;
        for (int i = 0; i < v; i++)
        {
            connectivity = 0;
            // visitNodes(adj[i], connectivity);
            if (connectivity != v)
                return false;
        }
        return true;
    }

private:
    void visitNodes(T source, int &c)
    {
        int visited[v];
        for (int i = 0; i < v; i++)
            visited[i] = 0;

        stack<T> s;
        s.push(source);
        visited[search(source)] = 1;
        T temp;

        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            c++;
            Node<T> *temp_list = adj[search(temp)];

            while (temp_list)
            {
                if (visited[search(temp_list->data)] != 1)
                {
                    visited[search(temp_list->data)] = 1;
                    s.push(temp_list->data);
                }
                temp_list = temp_list->next;
            }
        }
    }
};

int main()
{
    // Graph<string> g;
    // string city;
    // char ch = 'y';
    // int choice;
    // while (ch == 'y')
    // {
    //     cout << "\nChoose an operation:\n"
    //          << "1. Display adjacency list\n"
    //          << "2. Perform BFS traversal\n"
    //          << "3. Perform DFS traversal\n"
    //          << "4. Calculate Indegree and Outdegree of all nodes\n"
    //          << "5. Check if the graph is connected\n"
    //          << "Enter your choice: ";
    //     cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         g.show();
    //         break;
    //     case 2:
    //         cout << "Enter the source city: ";
    //         cin >> city;
    //         g.bfs(city);
    //         break;
    //     case 3:
    //         cout << "Enter the source city: ";
    //         cin >> city;
    //         g.dfs(city);
    //         break;
    //     case 4:
    //         g.in_out_degree();
    //         break;
    //     case 5:
    //         if (g.isConnected())
    //             cout << "Yes, the graph is connected" << endl;
    //         else
    //             cout << "Yes, the graph is not connected" << endl;
    //         break;
    //     default:
    //         cout << "Invalid choice, please try again.\n";
    //     }

    //     cout << "Do you want to continue? (y/n): ";
    //     cin >> ch;
    // }
    
    Queue<int> s;
    s.enqueue(1);
    s.enqueue(2);
    cout<<s.peek()<<endl;
    
    s.dequeue();
    cout<<s.peek()<<endl;
    s.dequeue();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty();
    // cout<<s.top();
    return 0;
}