#include <iostream>
using namespace std;

void zero_one(int profit[],int weight[],int n,int capacity){
    int zero_one_matrix[n+1][capacity+1];
    for(int i=0;i<(capacity+1);i++)
    zero_one_matrix[0][i]=0;
    for(int i=0;i<(n+1);i++)
    zero_one_matrix[i][0]=0;
    
    for(int i=1;i<(n+1);i++){
        for(int j=0;j<(capacity+1);j++){
            if(weight[i-1]<=j){
                if(profit[i-1]+zero_one_matrix[i-1][j-weight[i-1]]>zero_one_matrix[i-1][j]){
                    zero_one_matrix[i][j]=profit[i-1]+zero_one_matrix[i-1][j-weight[i-1]];
                }
                else{
                   zero_one_matrix[i][j]=zero_one_matrix[i-1][j]; 
                }
            }
            else{
                zero_one_matrix[i][j]=zero_one_matrix[i-1][j];
            }
        }
    }
    
    
    for(int i=0;i<(n+1);i++){
        for(int j=0;j<(capacity+1);j++){
            cout<<zero_one_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int k=capacity;
    int i=n;
    int ans=0;
    while(i>=0 && k>=0){
        if(zero_one_matrix[i][k]!=zero_one_matrix[i-1][k]){
            i-=1;
            k=k-weight[i];
            ans+=profit[i];
            cout<<profit[i]<<" "<<weight[i]<<endl;
        }
        else
            i-=1;
    }
    
    cout<<ans;
    
}

int main() {
    cout<<"Enter n: ";
    int n;
    cin>>n;
    int profit[n];
    int weight[n];
    cout<<"Enter Profit and weight ratio: ";
    for(int i=0;i<n;i++){
        cin>>profit[i]>>weight[i];
    }
    cout<<"Enter Capacity: ";
    int capacity;
    cin>>capacity;
    zero_one(profit,weight,n,capacity);

    return 0;
}
