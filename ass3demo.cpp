#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// selection sort

class SelectionSort {
public:
    void sort(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i; // pahile he index1 la minimunconsider karate next index2 la like end paryant

            for (int j = i + 1; j < n; j++) {//minimum index passun pudchya index chi compare karate ani 
                //jar pudchi index cha element greater asel tar swap karnar with minimum index,(sorted arr with unsorted arr)
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]); // greedy choice
        }
    }
};

// job scheduling problem

class JobScheduling {
    struct Job {
        char id;
        int deadline;
        int profit;
    };

public:
//adhi profit la sort arayache ascendig order ne nantar
//nantar travers karache tya arr madhe ani tya job chi deadline ghyayachi
    void schedule() {
        vector<Job> jobs = {
            {'A', 2, 100},
            {'B', 1, 19},
            {'C', 2, 27},
            {'D', 1, 25},
            {'E', 3, 15}
        };

        sort(jobs.begin(), jobs.end(), // sort jobs by profit
             [](Job a, Job b) { return a.profit > b.profit; });

        int maxDeadline = 0;
        for (auto j : jobs)//if jobs deadline is 1 2 3 then it return maxdeadline 3
            maxDeadline = max(maxDeadline, j.deadline);

        vector<char> result(maxDeadline, '-');//make result arr [-,-,-] like this
        vector<bool> slot(maxDeadline, false);//initially mark slot array to false 

        for (auto job : jobs) {
            for (int t = job.deadline - 1; t >= 0; t--) {//backward loop (decending order)
                if (!slot[t]) {//check slot is true i.e empty  
                    slot[t] = true;
                    result[t] = job.id;
                    break;
                }
            }
        }

        cout << "Job Scheduling Order: ";
        for (char c : result)
            if (c != '-') cout << c << " ";
        cout << endl;
    }
};

// single source shortest path

class SingleSourceShortestPath {
    int V;

public:
    SingleSourceShortestPath(int vertices) {
        V = vertices;
    }

    void dijkstra(vector<vector<int>>& graph, int src) {
        vector<int> dist(V, INT_MAX);
        vector<bool> explored(V, false);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> frontier;

        dist[src] = 0;
        frontier.push({0, src});

        while (!frontier.empty()) {
            int u = frontier.top().second;
            frontier.pop();

            if (explored[u]) continue;
            explored[u] = true; // add to EXPLORED

            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !explored[v] &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    frontier.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " : " << dist[i] << endl;
    }
};

// prim's minimum spanning tree

class PrimsMST {
    int V;

public:
    PrimsMST(int vertices) {
        V = vertices;
    }

    void primMST(vector<vector<int>>& graph) {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> frontier;

        key[0] = 0;
        frontier.push({0, 0});

        while (!frontier.empty()) {
            int u = frontier.top().second;
            frontier.pop();

            if (inMST[u]) continue;
            inMST[u] = true; // EXPLORED

            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                    parent[v] = u;
                    frontier.push({key[v], v});
                }
            }
        }

        cout << "Prim's MST Edges:\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i
                 << " (Weight: " << graph[i][parent[i]] << ")\n";
    }
};

int main() {

    // selection sort
    SelectionSort ss;
    vector<int> arr = {64, 25, 12, 22, 11};
    ss.sort(arr);
    cout << "Selection Sort Result: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // job scheduling
    JobScheduling js;
    js.schedule();
    cout << "\n";

    // single source shortest path
    vector<vector<int>> graphSSSP = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 0},
        {0, 0, 4, 0, 3},
        {5, 2, 0, 3, 0}
    };

    SingleSourceShortestPath sssp(5);
    sssp.dijkstra(graphSSSP, 0);
    cout << "\n";

    // prim's MST
    vector<vector<int>> graphMST = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    PrimsMST mst(5);
    mst.primMST(graphMST);

    return 0;
}