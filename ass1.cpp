
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// //
// // ---------------- DFS USING RECURSION ----------------
// //
// bool dfs_recursive(int node, int exitNode,
//                    vector<vector<int>> &adj,
//                    vector<bool> &visited,
//                    vector<int> &path) {

//     visited[node] = true;        // mark visited
    
//     path.push_back(node);        // add to path

//     if (node == exitNode)
//         return true;             // exit found

//     for (int neighbor : adj[node]) {
//         if (!visited[neighbor]) {
//             if (dfs_recursive(neighbor, exitNode, adj, visited, path))
//                 return true;
//         }
//     }

//     // backtracking
//     path.pop_back();
//     return false;
// }

// //
// // ---------------- BFS ----------------
// //
// void bfs(int start, int exitNode, vector<vector<int>> &adj) {
//     int n = adj.size();
//     vector<bool> visited(n, false);
//     vector<int> parent(n, -1);

//     queue<int> q;
//     q.push(start);
//     visited[start] = true;

//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();

//         if (node == exitNode)
//             break;

//         for (int neighbor : adj[node]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 parent[neighbor] = node;
//                 q.push(neighbor);
//             }
//         }
//     }

//     // reconstruct path
//     vector<int> path;
//     for (int v = exitNode; v != -1; v = parent[v])
//         path.push_back(v);

//     cout << "Minimum cost path using BFS: ";
//     for (int i = path.size() - 1; i >= 0; i--)
//         cout << path[i] << " ";
//     cout << endl;
// }

// //
// // ---------------- MAIN ----------------
// //
// int main() {
//     int nodes, edges;
//     cout << "Enter number of nodes: ";
//     cin >> nodes;

//     cout << "Enter number of edges: ";
//     cin >> edges;

//     vector<vector<int>> adj(nodes + 1);   // 1-based indexing

//     cout << "Enter edges (u v):\n";
//     for (int i = 0; i < edges; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);   // undirected graph
//     }

//     int start, exitNode;
//     cout << "Enter start node: ";
//     cin >> start;

//     cout << "Enter exit node: ";
//     cin >> exitNode;

//     // ---------- DFS ----------
//     vector<bool> visited(nodes + 1, false);
//     vector<int> path;

//     if (dfs_recursive(start, exitNode, adj, visited, path)) {
//         cout << "Path using DFS (recursion): ";
//         for (int x : path)
//             cout << x << " ";
//         cout << endl;
//     } else {
//         cout << "No path found using DFS!" << endl;
//     }

//     // ---------- BFS ----------
//     bfs(start, exitNode, adj);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//
// ---------------- DFS USING RECURSION (MAZE) ----------------
//
bool dfs_recursive(int node, int exitNode,
                   vector<vector<int>> &adj,
                   vector<bool> &visited,
                   vector<int> &path) {

    visited[node] = true;
    path.push_back(node);

    if (node == exitNode)
        return true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs_recursive(neighbor, exitNode, adj, visited, path))
                return true;
        }
    }

    // Backtracking
    path.pop_back();
    return false;
}

//
// ---------------- BFS (WIFI SCANNING) ----------------
//
void bfs_wifi(int start, vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true; 
    q.push(start);

    cout << "Wi-Fi scan order (BFS): ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

//
// ---------------- MAIN ----------------
//
int main() {
    int choice;
    cout << "Choose Application:\n";
    cout << "1. Maze Solving (DFS)\n";
    cout << "2. Wi-Fi Scanning (BFS)\n";
    cout << "Enter choice: ";
    cin >> choice;

    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adj(nodes);   // 1-based indexing

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    if (choice == 1) {
        // -------- MAZE SOLVING (DFS) --------
        int start, exitNode;
        cout << "Enter start node: ";
        cin >> start;
        cout << "Enter exit node: ";
        cin >> exitNode;

        vector<bool> visited(nodes , false);
        vector<int> path;

        if (dfs_recursive(start, exitNode, adj, visited, path)) {
            cout << "Path using DFS (Maze): ";
            for (int x : path)
                cout << x << " ";
            cout << endl;
        } else {
            cout << "No path found in maze!" << endl;
        }
    }
    else if (choice == 2) {
        // -------- WIFI SCANNING (BFS) --------
        int start;
        cout << "Enter starting router: ";
        cin >> start;

        bfs_wifi(start, adj);
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}