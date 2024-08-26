#include <iostream>


const int MAX = 100;  // Maximum number of vertices

int adj[MAX][MAX];    // Adjacency matrix to store the graph
int visited[MAX];     // Array to keep track of visited vertices
int queue[MAX];       // Queue to store vertices for BFS
int front = 0, rear = 0;  // Pointers for the queue

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

bool isQueueEmpty() {
    return front == rear;
}

void bfs(int start, int n) {
    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start BFS from the given vertex
    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty()) {
        int u = dequeue();  // Get first unexplored vertex
        std::cout << u << " ";  // Print the vertex (optional, for demonstration)

        // Visit all adjacent vertices
        for (int w = 0; w < n; w++) {
            if (adj[u][w] == 1 && !visited[w]) {  // Check if w is adjacent to u and not visited
                enqueue(w);  // Insert w into the queue
                visited[w] = 1;  // Mark w as visited
            }
        }
    }
}

int main() {
    int n, e;  // Number of vertices and edges
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of edges: ";
    std::cin >> e;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    std::cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // Assuming the graph is undirected
    }

    int start;
    std::cout << "Enter the starting vertex: ";
    std::cin >> start;

    std::cout << "BFS traversal starting from vertex " << start << ":\n";
    bfs(start, n);

    return 0;
}
