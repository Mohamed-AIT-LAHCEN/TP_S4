#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graph {
    int V; // Number of vertices
    vector<int>* adj; // Pointer to an array containing adjacency lists

    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    ~Graph() {
        delete[] adj;
    }
};

void addEdge(Graph& graph, int v, int w) {
    graph.adj[v].push_back(w); // Add w to v’s list.
}

void DFSUtil(Graph& graph, int v, bool visited[]) {
    // Create a stack for DFS
    stack<int> stack;
    stack.push(v);

    while (!stack.empty()) {
        // Pop a vertex from stack and print it
        v = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So we need to print the popped item only if it is not visited.
        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        // Get all adjacent vertices of the popped vertex v. If an adjacent has not been visited, then push it to the stack.
        for (auto i = graph.adj[v].rbegin(); i != graph.adj[v].rend(); ++i) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
}

void DFS(Graph& graph, int v) {
    // Mark all the vertices as not visited
    bool* visited = new bool[graph.V];
    for (int i = 0; i < graph.V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, v, visited);

    delete[] visited;
}

int main() {
    Graph graph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    cout << "Parcours en profondeur à partir du sommet 0 :" << endl;
    DFS(graph, 0);

    return 0;
}