
#include <stdio.h>
#define n 4
    int arr[n][n];
    int stack[n];
    int top=-1;
    int visited[n];
    void DFS(int sv);
    
    void DFS(int sv){
        printf(" %d ",sv);
        stack[top++]=sv;
        visited[sv]=1;
     for(int i=0;i<n;i++){
    if(arr[sv][i]==1&&visited[i]!=1){
        DFS(i);
    }
}
}

int main () {

//input array
printf("Enter the adjacency matrix of graph\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    printf("Enter the element of index %d %d: ",i,j);
    scanf("%d",&arr[i][j]);
}
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    printf("%d ",arr[i][j]);
}
printf("\n");
}


    for(int j=0;j<n;j++){
        visited[j]=0;
    }
printf("Enter a starting vertex: ");
int sv;
scanf("%d",&sv);
printf("DFS serch is:\n");
 DFS(sv);


  return 0;
}


