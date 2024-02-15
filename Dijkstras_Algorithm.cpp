#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define n 5
int visited[5];

int smallest(int Q[n]){
  
    int s=999;
    int j=0;
    for(int i=0;i<n;i++){
        if(visited[i]!=1 && s>=Q[i]){
         s=Q[i];
         j=i;
        }
    }
    return j;
}


void printSolution(int Q[])
{   int sum=0;
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << " \t\t\t\t" << Q[i] << endl;
        sum+=Q[i];
    }
    cout<<endl<<sum;
}

int check(int matrix[n][n]){
int Q[n];
Q[0]=0;
visited[0]=0;
int i=0;

for(int i=1;i<n;i++){
    visited[i]=999;
}


for(int i=1;i<n;i++){
    Q[i]=999;
}

int k=1;
while(k<n){
    
    visited[i]=1;
    for(int j=0;j<n;j++){
         if(matrix[i][j]!=999 && Q[j]>Q[i]+matrix[i][j] )
         Q[j]=Q[i]+matrix[i][j];
    }
    k++;
   i=smallest(Q);
}
 

printSolution(Q);

}


int main(){
    // cout<<"Enter number of vertices: ";
    // cin>>n;
    cout<<endl<<"Enter adjacency matrix"<<endl;
    int matrix[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
           cin>>matrix[i][j];
      }
    }

    check(matrix);

    return 0;
}
