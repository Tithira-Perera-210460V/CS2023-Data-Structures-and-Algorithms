#include <iostream>
#include <vector>
using namespace std;

/* Finding the next vertex to visit
 by finding the minimum weighted edge connecting any tree vertex with the fringe vertices. */
int findNextNode(vector<int> weight, vector<bool> visited) {
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < weight.size(); v++){

        // Get the unvisited vertex with minimum edge weight
        if (!visited[v] && weight[v] < min){
            min = weight[v];
            minIndex = v;
        }
    }
    return minIndex;
}


// Displaying the obtained MST given the parent vertices and weights of edges
void printMST(vector<int> parentList, vector<int> weightList) {

    cout << "Edge \tWeight\n" << endl;

    for (int i = 0; i < parentList.size(); i++){
        if(parentList[i] != -1)
            cout << parentList[i] << " - " << i << " \t  " << weightList[i] << endl;
    }
}


/* Prim's Algorithm to find the minimum spanning tree,
   given the no. of vertices, weighted adjacency matrix and the root vertex */
void Prims_algorithm(vector<vector<int>> adjMatrix, int root) {
    int n = adjMatrix[0].size();

    vector<int> parentNodes(n);         //List of corresponding parent vertices
    vector<int> weight(n, INT_MAX);     //List of corresponding weights
    vector<bool> visited(n, false);     //List of visited/unvisited vertices

    //Setting up for root vertex
    weight[root] = 0;
    parentNodes[root] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = findNextNode(weight, visited); //Next node to visit
        visited[u] = true;      //Marking as visited

        //Checking minimum weighted edge for adjacent vertices
        for (int v = 0; v < n; v++)
            if (adjMatrix[u][v] != 0 && !visited[v] && adjMatrix[u][v] < weight[v]) {
                parentNodes[v] = u;
                weight[v] = adjMatrix[u][v];  //Updating parent list and weights list
            }
    }

    printMST(parentNodes, weight);  //Displaying final result
}


int main() {
    vector<vector<int>> tphonePoleGraph = { { 0, 3, 0, 0, 0, 1 },
                                            { 3, 0, 2, 1, 10, 0},
                                            { 0, 2, 0, 3, 0, 5},
                                            {0, 1, 3, 0, 5, 0},
                                            {0, 10, 0, 5, 0, 4},
                                            {1, 0, 5, 0, 4, 0} };
                        
    Prims_algorithm(tphonePoleGraph, 3);
}
