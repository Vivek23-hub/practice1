
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <climits>
// #include <unordered_set>  
// #include <string> 
// using namespace std;

// struct Node {
//     vector<vector<int>> state;
//     int x, y;
//     int g, h;
//     Node* parent;
// };

// // Goal state
// vector<vector<int>> goal = {
//     {2,0,1},
//     {3,5,4},
//     {6,8,7}
// };

// // Manhattan heuristic
// int heuristic(const vector<vector<int>> &s) {
//     int dist = 0;
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             if(s[i][j] != 0){
//                 int val = s[i][j] - 1;
//                 int gx = val / 3;
//                 int gy = val % 3;
//                 dist += abs(i - gx) + abs(j - gy);
//             }
//         }
//     }
//     return dist;
// }

// // Convert state → string
// string getKey(const vector<vector<int>> &s){
//     string k="";
//     for(auto &r:s)
//         for(int v:r)
//             k += to_string(v);
//     return k;
// }

// // Comparator
// struct Compare {
//     bool operator()(Node* a, Node* b){
//         return (a->g + a->h) > (b->g + b->h);
//     }
// };

// // Print grid
// void printState(const vector<vector<int>> &s, int step){
//     cout << "Step " << step << ":\n";
//     for(auto &row:s){
//         for(int v:row){
//             if(v==0) cout<<"_ ";
//             else cout<<v<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<"------\n";
// }

// // A* Algorithm
// void AStar(vector<vector<int>> start, int sx, int sy){

//     priority_queue<Node*, vector<Node*>, Compare> pq;
//     unordered_set<string> visited;

//     Node* root = new Node{start, sx, sy, 0, heuristic(start), NULL};//g -> 0 for first step
//     pq.push(root);
//     //sx means row of initial state i.e  position of zero
//     int iterations = 0;

//     int dx[] = {1,-1,0,0};
//     int dy[] = {0,0,1,-1};

//     while(!pq.empty()){
//         Node* cur = pq.top();
//         pq.pop();

//         string key = getKey(cur->state);
//         if(visited.count(key)) continue;
//         visited.insert(key);

//         iterations++;

//         // Goal reached
//         if(cur->h == 0){//cur is a pointer to a Node
//             vector<Node*> path;

//             while(cur){
//                 path.push_back(cur);
//                 cur = cur->parent;
//             }

//             reverse(path.begin(), path.end());

            

//             for(int i=0;i<path.size();i++){
//                 printState(path[i]->state, i);
//             }
//             cout << "\nSolution Found!\n";
//             cout << "Total Steps (moves): " << path.size()-1 << endl;
//             cout << "Total Iterations: " << iterations << "\n\n";
//             return;
//         }

//         // generate children
//         for(int i=0;i<4;i++){
//             int nx = cur->x + dx[i];//cur->x it is for
//             int ny = cur->y + dy[i];// cur->y :-column index of the blank tile (0) in the current node

//             if(nx>=0 && ny>=0 && nx<3 && ny<3){
//                 vector<vector<int>> newState = cur->state;
//                 //Create a new board named as newState, placing cur->state in it

//                 swap(newState[cur->x][cur->y],
//                      newState[nx][ny]);//Move blank tile
//                      //move zero 
//                      // pahilyanda zero current state cha hota mg to [nx][ny] new means move kelelya zero ne replace kela
//                      //Example:Before:4 0 6
//                                     //   4 0 6                  
//                                 //after 4 6 0

//                 Node* child = new Node{
//                     newState,
//                     nx, ny,
//                     cur->g + 1,//g increment by 1 for next step
//                     heuristic(newState),
//                     cur
//                 };

//                 pq.push(child);
//                 //Adds child node to OPEN list(priority queue) It will be selected //later based on lowest f(n)
 
//             }
//         }
//     }

//     //cout<<"No Solution Found\n";
// }

// int main(){

//     // 🔹 Predefined start state
//     vector<vector<int>> start = {
//         {2,8,3},
//         {1,6,4},
//         {7,0,5}
//     };

//     int sx, sy;

//     // find blank position
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             if(start[i][j] == 0){
//                 sx = i;//index of o means x co-ordinate of row(X)
//                 sy = j;//where zero is place i.e position of zero
//             }
//         }
//     }

//     AStar(start, sx, sy);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int x, y;
    int g, h;
    Node* parent;
};

// 🔹 Custom Goal state
vector<vector<int>> goal = {
    {2,0,1},
    {3,5,4},
    {6,8,7}
};

// 🔹 Correct Manhattan Heuristic for custom goal
int heuristic(const vector<vector<int>> &s) {
    int dist = 0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(s[i][j] != 0){
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        if(goal[x][y] == s[i][j]){
                            dist += abs(i - x) + abs(j - y);
                        }
                    }
                }
            }
        }
    }
    return dist;
}

// Convert state → string
string getKey(const vector<vector<int>> &s){
    string k="";
    for(auto &r:s)
        for(int v:r)
            k += to_string(v);
    return k;
}

// Comparator (min heap)
struct Compare {
    bool operator()(Node* a, Node* b){
        return (a->g + a->h) > (b->g + b->h);
    }
};

// 🔹 Print with step + iteration
void printState(const vector<vector<int>> &s, int step, int iter){
    cout << "Step " << step << " | Iteration " << iter << ":\n";
    for(auto &row:s){
        for(int v:row){
            if(v==0) cout<<"_ ";
            else cout<<v<<" ";
        }
        cout<<endl;
    }
    cout<<"------\n";
}

// A* Algorithm
void AStar(vector<vector<int>> start, int sx, int sy){

    priority_queue<Node*, vector<Node*>, Compare> pq;
    unordered_set<string> visited;

    Node* root = new Node{start, sx, sy, 0, heuristic(start), NULL};
    pq.push(root);

    int iterations = 0;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    while(!pq.empty()){
        Node* cur = pq.top();
        pq.pop();

        string key = getKey(cur->state);
        if(visited.count(key)) continue;
        visited.insert(key);

        iterations++;

        // 🔹 Optional: show search process
        cout << "Iteration " << iterations << ":\n";
        printState(cur->state, -1, iterations);

        // Goal check
        if(cur->h == 0){
            vector<Node*> path;

            while(cur){
                path.push_back(cur);
                cur = cur->parent;
            }

            reverse(path.begin(), path.end());

            cout << "\n===== FINAL SOLUTION PATH =====\n\n";

            for(int i=0;i<path.size();i++){
                printState(path[i]->state, i, iterations);
            }

            cout << "\nSolution Found!\n";
            cout << "Total Steps (moves): " << path.size()-1 << endl;
            cout << "Total Iterations: " << iterations << endl;

            return;
        }

        // Generate children
        for(int i=0;i<4;i++){
            int nx = cur->x + dx[i];
            int ny = cur->y + dy[i];

            if(nx>=0 && ny>=0 && nx<3 && ny<3){
                vector<vector<int>> newState = cur->state;

                swap(newState[cur->x][cur->y],
                     newState[nx][ny]);

                Node* child = new Node{
                    newState,
                    nx, ny,
                    cur->g + 1,
                    heuristic(newState),
                    cur
                };

                pq.push(child);
            }
        }
    }

    cout<<"No Solution Found\n";
}

int main(){

    // 🔹 Start state
    vector<vector<int>> start = {
        {2,8,3},
        {1,6,4},
        {7,0,5}
    };

    int sx, sy;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(start[i][j] == 0){
                sx = i;
                sy = j;
            }
        }
    }

    AStar(start, sx, sy);

    return 0;
}