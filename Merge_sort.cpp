#include <iostream>

using namespace std;

void Merge(int arr[],int l,int mid,int u){
    // n1 and n2 are ize of left and right array
    int n1=mid-l+1;
    int n2=u-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
            k++;
        }
        else{
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
     while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int l,int u){
    int mid=0;
    if(l<u){
        mid=(l+u)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,u);
        Merge(arr,l,mid,u);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int u=n-1;
    merge_sort(arr,l,u);
     for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }

    return 0;
}