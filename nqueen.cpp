// #include <iostream>
// #include <vector>
// using namespace std;

// class NQueens {
// private:
//     int n;
//     vector<int> board;

//     vector<bool> col;
//     vector<bool> leftDiag;
//     vector<bool> rightDiag;

//     int solutionCount;  // 🔥 count solutions

// public:
//     NQueens(int size) {
//         n = size;
//         board.resize(n, -1);

//         col.resize(n, false);
//         leftDiag.resize(2 * n - 1, false);
//         rightDiag.resize(2 * n - 1, false);

//         solutionCount = 0;
//     }

//     void printSolution() {
//         cout << "\nSolution " << solutionCount << ":\n";
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i] == j)
//                     cout << "Q ";
//                 else
//                     cout << ". ";
//             }
//             cout << endl;
//         }
//     }

//     // 🔹 Modified solve function
//     void solve(int row) {
//         if (row == n) {
//             solutionCount++;
//             printSolution();  // optional (remove if only count needed)
//             return;
//         }

//         for (int c = 0; c < n; c++) {

//             if (!col[c] &&
//                 !leftDiag[row - c + n - 1] &&
//                 !rightDiag[row + c]) {

//                 // Place queen
//                 board[row] = c;
//                 col[c] = true;
//                 leftDiag[row - c + n - 1] = true;
//                 rightDiag[row + c] = true;

//                 solve(row + 1);  //  explore all

//                 // Backtrack
//                 board[row] = -1;
//                 col[c] = false;
//                 leftDiag[row - c + n - 1] = false;
//                 rightDiag[row + c] = false;
//             }
//         }
//     }

//     void getResult() {
//         solve(0);
//         cout << "\nTotal solutions for n = " << n << " : " << solutionCount << endl;
//     }
// };

// int main() {
//     int n;
//     cout << "Enter value of n: ";
//     cin >> n;

//     if (n < 4 && n != 1) {
//         cout << "No solution exists for n = " << n << endl;
//         return 0;
//     }

//     NQueens q(n);
//     q.getResult();

//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

class NQueens {

private:

    int n;

    vector<int> board;

    vector<bool> col;
    vector<bool> leftDiag;
    vector<bool> rightDiag;

    int solutionCount;

    long long iterations;

public:

    NQueens(int size) {

        n = size;

        board.resize(n, -1);

        col.resize(n, false);

        leftDiag.resize(2 * n - 1, false);

        rightDiag.resize(2 * n - 1, false);

        solutionCount = 0;

        iterations = 0;
    }

    // ---------------- PRINT SOLUTION ----------------

    void printSolution() {

        cout << "\nSolution "
             << solutionCount
             << ":\n";

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }

    // ---------------- SOLVE FUNCTION ----------------

    void solve(int row) {

        iterations++; // count recursive calls

        // Base Case
        if (row == n) {

            solutionCount++;

            cout << "\nSolution "
                 << solutionCount
                 << " found at iteration: "
                 << iterations
                 << endl;

            printSolution();

            return;
        }

        // Try all columns
        for (int c = 0; c < n; c++) {

            iterations++; // count checking

            // Safe position check
            if (!col[c] &&
                !leftDiag[row - c + n - 1] &&
                !rightDiag[row + c]) {

                // Place Queen
                board[row] = c;

                col[c] = true;

                leftDiag[row - c + n - 1] = true;

                rightDiag[row + c] = true;

                // Recursive call
                solve(row + 1);

                // Backtracking
                board[row] = -1;

                col[c] = false;

                leftDiag[row - c + n - 1] = false;

                rightDiag[row + c] = false;
            }
        }
    }

    // ---------------- RESULT ----------------

    void getResult() {

        solve(0);

        cout << "\nTotal solutions for n = "
             << n
             << " : "
             << solutionCount
             << endl;

        cout << "Total iterations: "
             << iterations
             << endl;
    }
};

// ---------------- MAIN ----------------

int main() {

    int n;

    cout << "Enter value of n: ";

    cin >> n;

    if (n < 4 && n != 1) {

        cout << "No solution exists for n = "
             << n
             << endl;

        return 0;
    }

    NQueens q(n);

    q.getResult();

    return 0;
}
