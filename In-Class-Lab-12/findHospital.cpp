#include <iostream>
#include <vector>
using namespace std;


//Finding the vertex with minimum distance value, from the set of vertices not yet visited in the graph
int minDistance(vector<int> dist, vector<bool> visited) {
    int min = INT_MAX;
    int minIndex;
  
    for (int v = 0; v < dist.size(); v++){
        if (visited[v] == false && dist[v] <= min){
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}


//Dijkstra's Algorithm to find the shortest distance from a source node to all other nodes
vector<int> Dijkstras_algorithm(int n, vector<vector<int>> adjMatrix, int source){
    vector<int> distances(n, INT_MAX);
    vector<bool> visited(n, false);

    distances[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        
        int node = minDistance(distances, visited);
        visited[node] = true;

        for (int vertex = 0; vertex < n; vertex++)
            if (!visited[vertex]){
                int weight = adjMatrix[node][vertex];

                if(adjMatrix[node][vertex] != 0 && distances[node] != INT_MAX && distances[node] + weight < distances[vertex])
                    distances[vertex] = distances[node] + weight;
            }
    }

    return distances;
}


//Printing the shortest time for all cities from a source city
void printTime(vector<int> time,int source){
    cout << "From City " << source << " : " << endl;

    for (size_t i = 0; i < time.size(); ++i){
        if(time[i] != 0)
            cout << "\tShortest time to City " << i << " = " << time[i] << endl;
    }

    cout << endl;
}


//Printing the shortest time from all cities
void printTimeForAll(vector<vector<int>> graph, int cityCount){
    for (int i = 0; i < cityCount; ++i){
        vector<int> time = Dijkstras_algorithm(cityCount, graph, i);
        printTime(time, i);
    }
}


//Finding the city to build the hospital under given conditions
void find_closest_city(vector<vector<int>> AdjMatrix, int n) {
    vector<int> avgTime(n, 0);

    for (int i = 0; i < n; ++i) {
        vector<int> time = Dijkstras_algorithm(n, AdjMatrix, i);

        for (int j = 0; j < time.size(); ++j) {
            avgTime[j] += time[j];
        }
    }

    int minAvgTime = INT_MAX;
    vector<int> closestCities;

    for (int i = 0; i < avgTime.size(); i++) {
        avgTime[i] = avgTime[i] / (n - 1);

        if (avgTime[i] < minAvgTime) {
            minAvgTime = avgTime[i];
            closestCities.clear();
            closestCities.push_back(i);
        } else if (avgTime[i] == minAvgTime) {
            closestCities.push_back(i);
        }
    }

    cout << "Cities with the smallest average time: ";
    for (int city : closestCities) {
        cout << city << " ";
    }
    cout << endl;
}


int main(){
    vector<vector<int>> cityMap = { {0, 10, 0, 0, 15, 5},
                                    {10, 0, 10, 30, 0, 0},
                                    {0, 10, 0, 12, 5, 0},
                                    {0, 30, 12, 0, 0, 20},
                                    {15, 0, 5, 0, 0, 0},
                                    {5, 0, 0, 20, 0, 0}  };    

    printTimeForAll(cityMap, 6);
    find_closest_city(cityMap, 6);
  
    return 0;
}
