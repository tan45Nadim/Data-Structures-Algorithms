#include <iostream>
#include <queue>
using namespace std;

int node, edge;
int graph[100][100];
bool visited[100];
int level[100];
int parent[100];

void AdjacentMatrix() {
    cout << "Adjacent Matrix: " << endl;
    for(int i=1; i<=node; i++) {
        for(int j=1; j<=node; j++) {
            cout << graph[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void AdjacentNode(int source) {
    cout << "Adjacent Node of " << source << " are: ";
    for(int i=1; i<=node; i++) {
        if(graph[source][i] == 1) {
            cout << i << " ";
        }
    }cout << endl;
}

void Initialize() {
    for(int i=1; i<=node; i++) {
        visited[i] = false;
        parent[i] = -1;
        level[i] = -1;
    }
}

void DFS(int source) {
    cout << source << " ";
    visited[source] = true;
    for(int i=1; i<=node; i++) {
        if(graph[source][i] == 1 && visited[i] == false) {
            DFS(i);
        }
    }
}

void BFS(int source) {
    visited[source] = true;
    level[source] = 0;
    queue <int> q;
    q.push(source);

    while(!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int i=1; i<=node; i++) {
            if(graph[x][i] == 1 && visited[i] == false) {
                visited[i] = true;
                level[i] = level[x] + 1;
                parent[i] = x;
                q.push(i);
            }
        }
    }cout << endl;
}

int main() {
    cout << "Enter the number of nodes: ";
    cin >> node;
    cout << "Enter the number of edges: ";
    cin >> edge;

    int n1,n2;

    for(int i=1; i<=edge; i++) {
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
        graph[n2][n1] = 1;
    }

    AdjacentMatrix();

    for(int i=1; i<=node; i++) {
        AdjacentNode(i);
    }cout << endl;

    Initialize();
    cout << "DFS: ";
    DFS(1);
    Initialize();
    cout << "\nBFS: ";
    BFS(1);

    cout << "Level: ";
    for(int i=1; i<=node; i++) {
        cout << level[i] << " ";
    }

    cout << "\nParent: ";
    for(int i=1; i<=node; i++) {
        cout << parent[i] << " ";
    }

    return 0;
}

/**********************
input:
Enter the number of nodes: 10
Enter the number of edges: 13
1 4
1 2
4 3
2 3
3 10
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
0 1 0 1 0 0 0 0 0 0
1 0 1 0 1 0 1 1 0 0
0 1 0 1 0 0 0 0 1 1
1 0 1 0 0 0 0 0 0 0
0 1 0 0 0 1 1 1 0 0
0 0 0 0 1 0 0 0 0 0
0 1 0 0 1 0 0 1 0 0
0 1 0 0 1 0 1 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0

Adjacent Node of 1 are: 2 4
Adjacent Node of 2 are: 1 3 5 7 8
Adjacent Node of 3 are: 2 4 9 10
Adjacent Node of 4 are: 1 3
Adjacent Node of 5 are: 2 6 7 8
Adjacent Node of 6 are: 5
Adjacent Node of 7 are: 2 5 8
Adjacent Node of 8 are: 2 5 7
Adjacent Node of 9 are: 3
Adjacent Node of 10 are: 3

DFS: 1 2 3 4 9 10 5 6 7 8
BFS: 1 2 4 3 5 7 8 9 10 6
Level: 0 1 2 1 2 3 2 2 3 3
Parent: -1 1 2 1 2 5 2 2 3 3
**********************/
