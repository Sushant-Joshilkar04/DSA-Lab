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
         int j=i;
        }
    }
    return j;
}


void printSolution(int Q[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << " \t\t\t\t" << Q[i] << endl;
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
    i=smallest(Q);
    visited[k]=1;
    for(int j=0;j<n-1;j++){
         if(matrix[i][j]!=999 && Q[j]>Q[i]+matrix[i][j] )
         Q[j]=Q[i]+matrix[i][j];
    }
    k++;
   i++;
}

printSolution(Q);

}


int main(){
    // cout<<"Enter number of vertices: ";
    // cin>>n;
    cout<<endl<<"Enter adjacency matrix";
    int matrix[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
           cin>>matrix[i][j];
      }
    }

    check(matrix);

    return 0;
}








// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
// #include <iostream>
// using namespace std;
// #include <limits.h>

// // Number of vertices in the graph
// #define V 9

// // A utility function to find the vertex with minimum
// // distance value, from the set of vertices not yet included
// // in shortest path tree
// int minDistance(int dist[], bool sptSet[])
// {

// 	// Initialize min value
// 	int min = INT_MAX, min_index;

// 	for (int v = 0; v < V; v++)
// 		if (sptSet[v] == false && dist[v] <= min)
// 			min = dist[v], min_index = v;

// 	return min_index;
// }

// // A utility function to print the constructed distance
// // array
// void printSolution(int dist[])
// {
// 	cout << "Vertex \t Distance from Source" << endl;
// 	for (int i = 0; i < V; i++)
// 		cout << i << " \t\t\t\t" << dist[i] << endl;
// }

// // Function that implements Dijkstra's single source
// // shortest path algorithm for a graph represented using
// // adjacency matrix representation
// void dijkstra(int graph[V][V], int src)
// {
// 	int dist[V]; // The output array. dist[i] will hold the
// 				// shortest
// 	// distance from src to i

// 	bool sptSet[V]; // sptSet[i] will be true if vertex i is
// 					// included in shortest
// 	// path tree or shortest distance from src to i is
// 	// finalized

// 	// Initialize all distances as INFINITE and stpSet[] as
// 	// false
// 	for (int i = 0; i < V; i++)
// 		dist[i] = INT_MAX, sptSet[i] = false;

// 	// Distance of source vertex from itself is always 0
// 	dist[src] = 0;

// 	// Find shortest path for all vertices
// 	for (int count = 0; count < V - 1; count++) {
// 		// Pick the minimum distance vertex from the set of
// 		// vertices not yet processed. u is always equal to
// 		// src in the first iteration.
// 		int u = minDistance(dist, sptSet);

// 		// Mark the picked vertex as processed
// 		sptSet[u] = true;

// 		// Update dist value of the adjacent vertices of the
// 		// picked vertex.
// 		for (int v = 0; v < V; v++)

// 			// Update dist[v] only if is not in sptSet,
// 			// there is an edge from u to v, and total
// 			// weight of path from src to v through u is
// 			// smaller than current value of dist[v]
// 			if (!sptSet[v] && graph[u][v]
// 				&& dist[u] != INT_MAX
// 				&& dist[u] + graph[u][v] < dist[v])
// 				dist[v] = dist[u] + graph[u][v];
// 	}


// 	printSolution(dist);
// }

// int main()
// {

// 	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
// 						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
// 						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
// 						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
// 						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
// 						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
// 						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
// 						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
// 						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
// 	dijkstra(graph, 0);

// 	return 0;
// }
