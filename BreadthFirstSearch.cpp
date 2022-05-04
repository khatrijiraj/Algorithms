#include <iostream>
#include <list>
using namespace std;

class Graph {
    int vertex;
    list<int> *adj;

   public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int source);
};

Graph ::Graph(int v) {
    vertex = v;
    adj = new list<int>[v];
}

void Graph ::addEdge(int source, int destination) {
    adj[source].push_back(destination);
}

void Graph ::BFS(int source) {
    bool *visited = new bool[vertex];
    for (int i = 0; i < vertex; i++) {
        visited[i] = false;
    }

    list<int> queue;

    visited[source] = true;
    queue.push_back(source);
    list<int>::iterator i;
    while (!queue.empty()) {
        source = queue.front();
        queue.pop_front();
        cout << "Checking adjacent vertices for the vertex " << source << endl;
        for (i = adj[source].begin(); i != adj[source].end(); i++) {
            if (!visited[*i]) {
                cout << "Visit and enqueue " << *i << endl;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    int numberOfVertices, edges, a, b, source;
    cout << "Enter the number of vertices: ";
    cin >> numberOfVertices;
    Graph graph(numberOfVertices);
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter the edges with both vertices involved: ";
        cin >> a;
        cin >> b;
        graph.addEdge(a, b);
    }
    cout << "Enter the source: ";
    cin >> source;
    graph.BFS(source);

    return 0;
}