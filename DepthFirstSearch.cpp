#include <iostream>
#include <list>

using namespace std;

class Graph {
    int vertex;
    list<int> *adj;
    void DFSrecursive(int source, bool visited[]);

   public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int source);
};

Graph ::Graph(int v) {
    vertex = v;
    adj = new list<int>[v];
}

void Graph ::addEdge(int source, int destination) {
    adj[source].push_front(destination);
}

void Graph ::DFSrecursive(int source, bool visited[]) {
    visited[source] = true;
    cout << source << " ";
    list<int>::iterator i;
    for (i = adj[source].begin(); i != adj[source].end(); ++i) {
        if (!visited[*i]) {
            DFSrecursive(*i, visited);
        }
    }
}

void Graph ::DFS(int source) {
    bool *visited = new bool[vertex];
    for (int i = 0; i < vertex; i++) {
        visited[i] = false;
    }
    DFSrecursive(source, visited);
}

int main() {
    int noOfVertices, edges, a, b, source;
    cout << "Enter the number of vertices: ";
    cin >> noOfVertices;
    Graph G(noOfVertices);
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter the edges with both vertices involved: ";
        cin >> a;
        cin >> b;
        G.addEdge(a, b);
    }
    cout << "Enter the source: ";
    cin >> source;
    G.DFS(source);

    return 0;
}