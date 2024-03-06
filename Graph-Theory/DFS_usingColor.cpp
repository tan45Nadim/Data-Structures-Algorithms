#include <iostream>
using namespace std;

int time = 0;

void adjacentMatrix(int **graph, int node) {
    cout << "Adjacent Matrix: " << endl;
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << graph[i][j] << " ";
        } cout << endl;
    } cout << endl;
}

void DFS_VISIT(int **graph, int u, string *col, int *par, int node, int *sT, int *fT) {
    cout << u << " ";
    col[u] = "GRAY";
    sT[u] = ++time;
    for (int i = 0; i < node; i++) {
        if(graph[u][i] == 1 && col[i] == "WHITE") {
            par[i] = u;
            DFS_VISIT(graph, i, col, par, node, sT, fT);

        }
    }
    col[u] = "BLACK";
    fT[u] = ++time;
}

void DFS(int **graph, string *col, int *par, int node, int *sT, int *fT) {
    for (int i = 0; i < node; i++) {
        col[i] = "WHITE";
        par[i] = -1;
    }
    for (int i = 0; i < node; i++) {
        if (col[i] == "WHITE") {
            DFS_VISIT(graph, i, col, par, node, sT, fT);
        }
    }
}

int main() {
    cout << "Enter the number of nodes: ";
    int node; cin >> node;
    cout << "Enter the number of edges: ";
    int edge; cin >> edge;

    // Dynamically Allocate
    string *color = new string[node];
    int *parent = new int[node];
    int *startTime = new int[node];
    int *finishTime = new int[node];
    int **graph = new int*[node];
    for (int i = 0; i < node; i++) {
        graph[i] = new int[node];
    }
    // Initialize
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edge; i++) {
        int n1, n2; cin >> n1 >> n2;
        graph[n1][n2] = 1;
        graph[n2][n1] = 1;
    }
    adjacentMatrix(graph, node);

    cout << "DFS: ";
    DFS(graph, color, parent, node, startTime, finishTime);

    cout << endl << endl;;
    for (int i = 0; i < node; i++) {
        cout << "Node => " << i << ", Start Time => " << startTime[i] << ", Finish Time => " << finishTime[i] << endl;

    }


    // Delete the array
    for (int i = 0; i < node; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] color; delete[] parent;
    delete[] startTime; delete[] finishTime;

}


/**********************
input:
Enter the number of nodes: 10
Enter the number of edges: 13
1 4
1 2
4 3
2 3
3 0
3 9
2 5
2 7
2 8
5 6
8 5
8 7
7 5
**********************/

/**********************
output:
Adjacent Matrix:
0 0 0 1 0 0 0 0 0 0
0 0 1 0 1 0 0 0 0 0
0 1 0 1 0 1 0 1 1 0
1 0 1 0 1 0 0 0 0 1
0 1 0 1 0 0 0 0 0 0
0 0 1 0 0 0 1 1 1 0
0 0 0 0 0 1 0 0 0 0
0 0 1 0 0 1 0 0 1 0
0 0 1 0 0 1 0 1 0 0
0 0 0 1 0 0 0 0 0 0

DFS: 0 3 2 1 4 5 6 7 8 9

Node => 0, Start Time => 1, Finish Time => 20
Node => 1, Start Time => 4, Finish Time => 7
Node => 2, Start Time => 3, Finish Time => 16
Node => 3, Start Time => 2, Finish Time => 19
Node => 4, Start Time => 5, Finish Time => 6
Node => 5, Start Time => 8, Finish Time => 15
Node => 6, Start Time => 9, Finish Time => 10
Node => 7, Start Time => 11, Finish Time => 14
Node => 8, Start Time => 12, Finish Time => 13
Node => 9, Start Time => 17, Finish Time => 18

**********************/


/**********************
input:
Enter the number of nodes: 5
Enter the number of edges: 5
0 3
0 1
0 2
2 1
2 4
**********************/

/**********************
output:
Adjacent Matrix:
0 1 1 1 0
1 0 1 0 0
1 1 0 0 1
1 0 0 0 0
0 0 1 0 0

DFS: 0 1 2 4 3

Node => 0, Start Time => 1, Finish Time => 10
Node => 1, Start Time => 2, Finish Time => 7
Node => 2, Start Time => 3, Finish Time => 6
Node => 3, Start Time => 8, Finish Time => 9
Node => 4, Start Time => 4, Finish Time => 5

**********************/
