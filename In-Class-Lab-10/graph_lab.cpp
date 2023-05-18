#include <iostream>
#include<list>
#include<algorithm>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    int label;
    //2. a int type list called neighbours
    list<int> adjacencyList;

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label= (i + 1);
        }
    }

    void addedge(int u, int v){
        //check whether the given edge is already created by checking whether v is in u's adjacency list or not
        auto enteredVertex = find(nodes[u - 1].adjacencyList.begin(), nodes[u - 1].adjacencyList.end() , v);

        if (enteredVertex == nodes[u - 1].adjacencyList.end()){ //if the edge has not been created
            //select node u and push v into u's neighbour
            nodes[u-1].adjacencyList.push_back(v);

            //select node v and push u into v's neighbour
            nodes[v-1].adjacencyList.push_back(u);
        }
    }

    void print(){
        //lets iterate through each node and print its neighbours
        for (int i = 0; i < n; ++i){
            cout << (i + 1) << " --> [";

            for (auto it = nodes[i].adjacencyList.begin(); it != nodes[i].adjacencyList.end(); ++it) {
                //formatting the output for the final element
                if(*it == nodes[i].adjacencyList.back()){
                    cout << *it;
                    break;
                }
                
                cout << *it << ", ";
                
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.

    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(2,3);
    g->addedge(2,6);
    g->addedge(4,6);
    g->addedge(4,7);
    g->addedge(4,8);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);
    
    //print the graph adjaceny list
    g->print();

    delete g;

    return 0;
}
