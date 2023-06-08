#include <iostream>
#include <string>
using namespace std;
class Heap
{

public:
    int* heapArr;
    int n = 0;
    Heap(){
        cout<<"Enter number of elements"<<endl ;
        cin>>n;
        heapArr = new int[n];
        for (int i = 0; i < n; i++){
            heapArr[i] = 0;
        }
    }

    void heapSort(int arr[] ){
        for ( int i = (n/2)  - 1 ;i>=0; i -- ){
            HeapCreator( arr ,n, i );
        }
        for (int i =n - 1 ; i >= 0 ; i -- ){
            swap(arr[0] , arr[i]);
            HeapCreator(arr , i,0);
        }

    }

    void create(){
        int root, left, right;
        cout << "Enter the value of root:";
        cin >> root;
        heapArr[0] = root;
        for (int i = 0; i < (n/2); i++){
            cout << "Enter value of left child of "<<heapArr[i]<<" :";
            cin >> left;
            heapArr[2 * i + 1] = left;
            cout << "Enter value of right child of "<<heapArr[i]<<" :";
            cin >> right;
            heapArr[2 * i + 2] = right;
        }
    }

    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }

    void HeapCreator(int arr[],int N, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < N && arr[l] > arr[largest]){
            largest = l;
        }
        if (r < N && arr[r] > arr[largest]){
            largest = r;
        }
        if (largest != i){
            swap(arr[i], arr[largest]);
            HeapCreator(arr,N, largest);
        }
    }

    void maxHeap(int arr[])
    {
        int startIdx = (n/ 2) - 1;
        for (int i = startIdx; i >= 0; i--){
            HeapCreator(arr,n, i);
        }
    }

    void HeapCreator1(int arr[], int N, int i){
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < N && arr[l] < arr[smallest]){
            smallest = l;
        }
        if (r < N && arr[r] < arr[smallest]){
            smallest = r;
        }
        if (smallest != i){
            swap(arr[i], arr[smallest]);
            HeapCreator1(arr, N, smallest);
        }
    }

    void minHeap(int arr[]){
        int startIdx = (n / 2) - 1;
        for (int i = startIdx; i >= 0; i--){
            HeapCreator1(arr, n, i);
        }
    }

    void display(){
        for (int i = 0; i < n; i++){
            cout << heapArr[i] << " ";
        }
    }

    void insert(int arr[] ){
    	int newElem ;
    	cin >> newElem ;
    	n++ ;
    	arr[n - 1] = newElem ;
    	int i = n - 1 ;
    	while(i > 0  && arr[i] > arr[(i-1)/2]){
    		swap(arr[i] , arr[( i - 1 ) /2 ]);
    		i = (i - 1) / 2 ;
    	}
    }

    void deleteHeap(int arr[]) {
        swap(arr[0],arr[n-1]);
        n = n - 1;
        HeapCreator1(arr,n, 0);
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Heap h;
    h.create();
    h.display();
    cout << endl;

    h.maxHeap(h.heapArr);
    cout << "MAX Heap array :" << endl;
    h.display();
    cout<<endl;

    h.insert(h.heapArr);
    cout << "After insertion :" << endl;
    h.display();
    cout<<endl;


    h.minHeap(h.heapArr);
    cout << "MIN Heap array :" << endl;
    h.display();
    cout << endl;

    h.heapSort(h.heapArr);
    cout << "Sort the heap :" << endl;
    h.display();
    cout<<endl;




    cout << "After deletion :" << endl;
    h.deleteHeap(h.heapArr);




    return 0;
}