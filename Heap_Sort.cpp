#include <iostream>
using namespace std;

void heapify(int arr[], int N, int i){
    int parent = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<N && arr[left]>arr[parent] && arr[left]>arr[right]){
	swap(arr[left], arr[parent]);
	heapify(arr, N, left);
	}
	if (right<N && arr[right]>arr[parent] && arr[left]<arr[right]){
	swap(arr[right], arr[parent]);
	heapify(arr, N, right);
	}
	
}


void heapsort(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--)
	heapify(arr, n, i);
		
	for (int i = n - 1; i > 0; i--){
	swap(arr[0], arr[i]);
    heapify(arr,i,0);
	}
    
}

void print(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    heapsort(arr,n);
    print(arr,n);

    return 0;
}
