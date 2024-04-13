#include<bits/stdc++.h> 
 
using namespace std; 
 
int visit[6]={0}; 
int stk[6]; 
int top=-1; 
int arr[6][6]; 
 
void dfs(int a){ 
  
  if(visit[a]==0){ 
     visit[a]=1; 
     cout<<a<<endl; 
     top++; 
     stk[top]=a; 
   } 
   for(int j=0;j<6;j++){ 
     if(arr[a][j]==1 && !visit[j]){ 
         dfs(j); 
         break; 
     } 
   } 
} 
 
void pop(){ 
  while(top!=-1){ 
     dfs(stk[top]); 
     top--; 
  } 
} 
 
int main(){ 
  
  cout<<"Enter Adejecancy Matrix of a Graph"<<endl; 
 
  for(int i=0;i<6;i++){ 
     for(int j=0;j<6;j++){ 
         cin>>arr[i][j]; 
     } 
  } 
 
  dfs(0); 
  pop(); 
  return 0; 
} 
#include<iostream> 
using namespace std; 
 
int visit[5]={0}; 
int arr[5][5]; 
int queue[5]; 
int n=5; 
int front=-1,rear=-1; 
 
void bfs(int vertex){ 
  
  if(front>=n) return; 
  
  if(front==-1){ 
    visit[vertex]=1; 
    front++; 
    rear++; 
    queue[rear]=vertex; 
    
  } 
  front++; 
  cout<<vertex<<endl; 
  for(int i=0;i<n;i++){ 
     if(arr[vertex][i]==1 && !visit[i]){ 
          rear++; 
          queue[rear]=i; 
          visit[i]=1; 
     } 
  } 
  
  bfs(queue[front]); 
  
} 
 
void getdata(){ 
  for(int i=0;i<n;i++){ 
     for(int j=0;j<n;j++){ 
        cin>>arr[i][j]; 
     } 
  } 
} 
 
 
int main(){ 
 cout<<"Please Enter adjecent matrix for Breadth FIrst search Traversal-"<<endl; 
 getdata(); 
 bfs(0); 
  
return 0; 
} 
// #include <stdio.h>
// #define n 4
//     int arr[n][n];
//     int stack[n];
//     int top=-1;
//     int visited[n];
//     void DFS(int sv);
    
//     void DFS(int sv){
//         printf(" %d ",sv);
//         stack[top++]=sv;
//         visited[sv]=1;
//      for(int i=0;i<n;i++){
//     if(arr[sv][i]==1&&visited[i]!=1){
//         DFS(i);
//     }
// }
// }

// int main () {

// //input array
// printf("Enter the adjacency matrix of graph\n");
// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//     printf("Enter the element of index %d %d: ",i,j);
//     scanf("%d",&arr[i][j]);
// }
// }

// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//     printf("%d ",arr[i][j]);
// }
// printf("\n");
// }


//     for(int j=0;j<n;j++){
//         visited[j]=0;
//     }
// printf("Enter a starting vertex: ");
// int sv;
// scanf("%d",&sv);
// printf("DFS serch is:\n");
//  DFS(sv);


//   return 0;
// }


