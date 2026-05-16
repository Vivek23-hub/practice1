// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <climits>
// using namespace std;

// // selection sort

// class SelectionSort {
// public:
//     void sort(vector<int>& arr) {
//         int n = arr.size();

//         for (int i = 0; i < n - 1; i++) {
//             int minIndex = i; // pahile he index1 la minimunconsider karate next index2 la like end paryant

//             for (int j = i + 1; j < n; j++) {//minimum index passun pudchya index chi compare karate ani 
//                 //jar pudchi index cha element greater asel tar swap karnar with minimum index,(sorted arr with unsorted arr)
//                 if (arr[j] < arr[minIndex]) {
//                     minIndex = j;
//                 }
//             }
//             swap(arr[i], arr[minIndex]); // greedy choice
//         }
//     }
// };

// // job scheduling problem

// class JobScheduling {
//     struct Job {
//         char id;
//         int deadline;
//         int profit;
//     };

// public:
// //adhi profit la sort arayache ascendig order ne nantar
// //nantar travers karache tya arr madhe ani tya job chi deadline ghyayachi
//     void schedule() {
//         vector<Job> jobs = {
//             {'A', 2, 100},
//             {'B', 1, 19},
//             {'C', 2, 27},
//             {'D', 1, 25},
//             {'E', 3, 15}
//         };

//         sort(jobs.begin(), jobs.end(), // sort jobs by profit
//              [](Job a, Job b) { return a.profit > b.profit; });

//         int maxDeadline = 0;
//         for (auto j : jobs)//if jobs deadline is 1 2 3 then it return maxdeadline 3
//             maxDeadline = max(maxDeadline, j.deadline);

//         vector<char> result(maxDeadline, '-');//make result arr [-,-,-] like this
//         vector<bool> slot(maxDeadline, false);//initially mark slot array to false 

//         for (auto job : jobs) {
//             for (int t = job.deadline - 1; t >= 0; t--) {//backward loop (decending order)
//                 if (!slot[t]) {//check slot is true i.e empty  
//                     slot[t] = true;
//                     result[t] = job.id;
//                     break;
//                 }
//             }
//         }

//         cout << "Job Scheduling Order: ";
//         for (char c : result)
//             if (c != '-') cout << c << " ";
//         cout << endl;
//     }
// };

// // single source shortest path

// class SingleSourceShortestPath {
//     int V;

// public:
//     SingleSourceShortestPath(int vertices) {
//         V = vertices;
//     }

//     void dijkstra(vector<vector<int>>& graph, int src) {
//         vector<int> dist(V, INT_MAX);
//         vector<bool> explored(V, false);

//         priority_queue<pair<int, int>,
//                        vector<pair<int, int>>,
//                        greater<pair<int, int>>> frontier;

//         dist[src] = 0;
//         frontier.push({0, src});

//         while (!frontier.empty()) {
//             int u = frontier.top().second;
//             frontier.pop();

//             if (explored[u]) continue;
//             explored[u] = true; // add to EXPLORED

//             for (int v = 0; v < V; v++) {
//                 if (graph[u][v] && !explored[v] &&
//                     dist[u] + graph[u][v] < dist[v]) {
//                     dist[v] = dist[u] + graph[u][v];
//                     frontier.push({dist[v], v});
//                 }
//             }
//         }

//         cout << "Shortest distances from source " << src << ":\n";
//         for (int i = 0; i < V; i++)
//             cout << "Node " << i << " : " << dist[i] << endl;
//     }
// };

// // prim's minimum spanning tree

// class PrimsMST {
//     int V;

// public:
//     PrimsMST(int vertices) {
//         V = vertices;
//     }

//     void primMST(vector<vector<int>>& graph) {
//         vector<int> key(V, INT_MAX);
//         vector<bool> inMST(V, false);
//         vector<int> parent(V, -1);

//         priority_queue<pair<int, int>,
//                        vector<pair<int, int>>,
//                        greater<pair<int, int>>> frontier;

//         key[0] = 0;
//         frontier.push({0, 0});

//         while (!frontier.empty()) {
//             int u = frontier.top().second;
//             frontier.pop();

//             if (inMST[u]) continue;
//             inMST[u] = true; // EXPLORED

//             for (int v = 0; v < V; v++) {
//                 if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
//                     key[v] = graph[u][v];
//                     parent[v] = u;
//                     frontier.push({key[v], v});
//                 }
//             }
//         }

//         cout << "Prim's MST Edges:\n";
//         for (int i = 1; i < V; i++)
//             cout << parent[i] << " - " << i
//                  << " (Weight: " << graph[i][parent[i]] << ")\n";
//     }
// };

// int main() {

//     // selection sort
//     SelectionSort ss;
//     vector<int> arr = {64, 25, 12, 22, 11};
//     ss.sort(arr);
//     cout << "Selection Sort Result: ";
//     for (int x : arr) cout << x << " ";
//     cout << "\n\n";

//     // job scheduling
//     JobScheduling js;
//     js.schedule();
//     cout << "\n";

//     // single source shortest path
//     vector<vector<int>> graphSSSP = {
//         {0, 10, 0, 0, 5},
//         {10, 0, 1, 0, 2},
//         {0, 1, 0, 4, 0},
//         {0, 0, 4, 0, 3},
//         {5, 2, 0, 3, 0}
//     };

//     SingleSourceShortestPath sssp(5);
//     sssp.dijkstra(graphSSSP, 0);
//     cout << "\n";

//     // prim's MST
//     vector<vector<int>> graphMST = {
//         {0, 2, 0, 6, 0},
//         {2, 0, 3, 8, 5},
//         {0, 3, 0, 0, 7},
//         {6, 8, 0, 0, 9},
//         {0, 5, 7, 9, 0}
//     };

//     PrimsMST mst(5);
//     mst.primMST(graphMST);

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ---------------- FOOD DELIVERY ----------------
class FoodDeliveryScheduling {
    struct Order {
        char id;
        int deadline;
        int priority;
    };

public:
    void schedule() {
        vector<Order> orders = {
            {'A', 2, 100},
            {'B', 1, 19},
            {'C', 2, 27},
            {'D', 1, 25},
            {'E', 3, 15}
        };

        sort(orders.begin(), orders.end(),
             [](Order a, Order b) {
                 return a.priority > b.priority;
             });

        int maxDeadline = 0;
        for (auto o : orders)
            maxDeadline = max(maxDeadline, o.deadline);

        vector<char> result(maxDeadline, '-');
        vector<bool> slot(maxDeadline, false);

        for (auto order : orders) {
            for (int t = order.deadline - 1; t >= 0; t--) {
                if (!slot[t]) {
                    slot[t] = true;
                    result[t] = order.id;
                    break;
                }
            }
        }

        cout << "\nFood Delivery Order Sequence: ";
        for (char c : result)
            if (c != '-') cout << c << " ";
        cout << endl;
    }
};

// ---------------- PRIM'S ----------------
class RailwayTracks {
    int V;
    vector<string> cities;

public:
    RailwayTracks(int v, vector<string> c) {
        V = v;
        cities = c;
    }

    int minKey(vector<int>& key, vector<bool>& mstSet) {
        int min = INT_MAX, min_index;
        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && key[i] < min) {
                min = key[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void primMST(vector<vector<int>>& graph) {
        vector<int> parent(V);
        vector<int> key(V, INT_MAX);
        vector<bool> mstSet(V, false);

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        cout << "\nRailway Track Connections:\n";
        int totalCost = 0;

        for (int i = 1; i < V; i++) {
            cout << cities[parent[i]] << " - " << cities[i]
                 << " Cost: " << graph[parent[i]][i] << endl;
            totalCost += graph[parent[i]][i];
        }

        cout << "Total Cost: " << totalCost << endl;
    }
};

// ---------------- STUDENT SORT ----------------
class Student {
public:
    int id;
    string name;
    float marks;

    Student(int id, string name, float marks) {
        this->id = id;
        this->name = name;
        this->marks = marks;
    }
};

void sortStudents(vector<Student>& students, int order) {
    int n = students.size();

    for(int i = 0; i < n; i++) {
        int selectedIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(order == 0) {
                if(students[j].marks < students[selectedIndex].marks)
                    selectedIndex = j;
            } else {
                if(students[j].marks > students[selectedIndex].marks)
                    selectedIndex = j;
            }
        }
        swap(students[i], students[selectedIndex]);
    }
}

void display(vector<Student>& students) {
    cout << "Id\tName\tMarks\n";
    for(auto &s : students) {
        cout << s.id << "\t" << s.name << "\t" << s.marks << endl;
    }
}

// ---------------- DIJKSTRA ----------------
class Dijkstra {
    int V;
    vector<string> cities;

public:
    Dijkstra(int v, vector<string> c) {
        V = v;
        cities = c;
    }

    int minDistance(vector<int>& dist, vector<bool>& visited) {
        int min = INT_MAX, min_index;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void shortestPath(vector<vector<int>>& graph, int src, int dest) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (!visited[v] && graph[u][v] &&
                    dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "\nShortest Distance: " << dist[dest] << endl;
        cout << "Path: ";
        printPath(parent, dest);
        cout << endl;
    }

    void printPath(vector<int>& parent, int j) {
        if (j == -1) return;
        printPath(parent, parent[j]);
        cout << cities[j] << " ";
    }
};

// ---------------- MAIN MENU ----------------
int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Food Delivery\n";
        cout << "2. Railway (Prim's)\n";
        cout << "3. Student Sorting\n";
        cout << "4. Dijkstra Shortest Path\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                FoodDeliveryScheduling f;
                f.schedule();
                break;
            }

            case 2: {
                vector<string> cities = {"Pune","Mumbai","Nashik","Nagpur"};
                vector<vector<int>> graph = {
                    {0,30,20,80},
                    {30,0,60,0},
                    {20,60,0,50},
                    {80,0,50,0}
                };

                RailwayTracks rt(4, cities);
                rt.primMST(graph);
                break;
            }

            case 3: {
                vector<Student> students;
                int n;
                cout << "Enter number of students: ";
                cin >> n;

                for(int i=0;i<n;i++){
                    int id; string name; float marks;
                    cout << "Enter id name marks: ";
                    cin >> id >> name >> marks;
                    students.push_back(Student(id,name,marks));
                }

                display(students);

                int order;
                cout << "0-Asc 1-Desc: ";
                cin >> order;

                sortStudents(students, order);
                display(students);
                break;
            }

            case 4: {
                vector<string> cities = {"Pune","Mumbai","Nashik","Nagpur"};
                vector<vector<int>> graph = {
                    {0,30,20,80},
                    {30,0,60,0},
                    {20,60,0,50},
                    {80,0,50,0}
                };

                int src, dest;
                cout << "Cities:\n";
                for(int i=0;i<cities.size();i++)
                    cout << i << " -> " << cities[i] << endl;

                cout << "Enter source: ";
                cin >> src;
                cout << "Enter destination: ";
                cin >> dest;

                Dijkstra dj(4, cities);
                dj.shortestPath(graph, src, dest);
                break;
            }

        }

    } while(choice != 5);

    return 0;
}
