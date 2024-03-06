#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

void adjacentMatrix(int **graph, int node) {
    cout << "Adjacent Matrix: " << endl;
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << graph[i][j] << " ";
        } cout << endl;
    } cout << endl;
}

void BFS(int **graph, int source, int node, string *col, int *par, int *dis) {
    for (int i = 0; i < node; i++) {
        col[i] = "WHITE";
        dis[i] = INT_MIN;
        par[i] = -1;
    }
    col[source] = "GRAY";
    dis[source] = 0;
    par[source] = -1;

    queue <int> q;
    q.push(source);

    while (!q.empty()) {
        int x;
        x = q.front();
        q.pop();
        col[x] = "GRAY";
        cout << x << " ";
        for (int i = 0; i < node; i++) {
            if ((graph[x][i] == 1) && (col[i] == "WHITE")) {
                col[i] = "GRAY";
                dis[i] = dis[x] + 1;
                par[i] = x;
                q.push(i);
            }
        }
        col[x] = "BLACK";
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
    int *distance = new int[node];
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

    cout << "BFS: ";
    BFS(graph, 1, node, color, parent, distance);

    cout << endl << endl;
    for (int i = 0; i < node; i++) {
        cout << "Node => " << i << ", Parent => " << parent[i] << ", Distance => " << distance[i] << endl;
    } cout << endl;

    // Delete the array
    for (int i = 0; i < node; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] color; delete[] parent; delete[] distance;

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

BFS: 1 2 4 3 5 7 8 0 9 6

Node => 0, Parent => 3, Distance => 3
Node => 1, Parent => -1, Distance => 0
Node => 2, Parent => 1, Distance => 1
Node => 3, Parent => 2, Distance => 2
Node => 4, Parent => 1, Distance => 1
Node => 5, Parent => 2, Distance => 2
Node => 6, Parent => 5, Distance => 3
Node => 7, Parent => 2, Distance => 2
Node => 8, Parent => 2, Distance => 2
Node => 9, Parent => 3, Distance => 3

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

BFS: 1 0 2 3 4

Node => 0, Parent => 1, Distance => 1
Node => 1, Parent => -1, Distance => 0
Node => 2, Parent => 1, Distance => 1
Node => 3, Parent => 0, Distance => 2
Node => 4, Parent => 2, Distance => 2

**********************/
