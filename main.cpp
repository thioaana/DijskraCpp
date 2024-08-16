#include <iostream>
using namespace std;


const int vertices = 9;
const int source = 0;
const int target = 4;

double findMinDist (bool visited[], double dist[]){
	double minDist = 10000.0;
	int minNode;
    for (int v = 0; v < vertices; v++){
        if (visited[v] == false && dist[v] < minDist){
            minDist = dist[v];
            minNode = v;
        }
    }	
	return minNode;
}

void dijskra (double g[vertices][vertices]){
    // Initialiazation
    bool visited[vertices];
    double dist[vertices];
    for (int i =0; i < vertices; ++i){
        visited[i] = false;
        dist[i] = 10000;
    }
    dist[source] = 0;

    for (int i = 0; i < vertices ; i++){
        int u = findMinDist(visited, dist); 
        visited[u] = true;
        
        //Testing
        cout << "u = " << u << endl; 
        for (int i = 0; i < vertices ; i++){
            cout << dist[i] << ", ";} 
        cout <<endl;

        for (int v=0; v< vertices; v++){
            cout << "v = " + to_string(v) << " --> g["+ to_string(u)+ "][]" + to_string(v) + "] = " + to_string(g[u][v]) << endl;
            if (g[u][v] > 0 && visited[v] == false 
                && dist[v] > dist[v] + g[u][v]){
                cout << "Makis";
                dist[v] = dist[v] + g[u][v];
            }
        }
    }
    for (int i = 0; i < vertices ; i++){
        cout << dist[i] << ", ";
    }
}

int main(){
    double graph [vertices][vertices] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                        {0, 0, 2, 0, 0, 0, 6, 7, 0}};
	


    dijskra(graph);
}


