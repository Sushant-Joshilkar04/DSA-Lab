#include <iostream>
using namespace std;

const int N = 4; // Number of queens (size of the chessboard)

// Function to check if a queen can be safely placed at [row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the left side of the current row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1)
            return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1)
            return false;
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the 4 Queens Problem
bool solveNQueens(int board[N][N], int col) {
    if (col >= N)
        return true; // All queens are placed successfully

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen

            // Recur for the next column
            if (solveNQueens(board, col + 1))
                return true;

            // If placing the queen doesn't lead to a solution, backtrack
            board[i][col] = 0; // Undo the placement
        }
    }

    return false; // No safe placement found
}

int main() {
    cout<<"Enter Rows: "<<endl;
    int board[N][N] = {0}; // Initialize the board with zeros

    if (solveNQueens(board, 0)) {
        // Print the solution
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}



/*
#include <iostream>
#include <vector>
using namespace std;

bool safe(vector<vector<int>>& visited, int x, int y, int n) {
    for (int i = 0; i < y; i++) {
        if (visited[x][i] == 1) {
            return false;
        }
    }
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (visited[i][j] == 1) {
            return false;
        }
    }
    for (int i = x, j = y; i < n && j >= 0; i++, j--) {
        if (visited[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void solve(vector<vector<int>>& visited, vector<int>& ans, vector<vector<int>>& res, int y, int n) {
    if (y == n) {
        res.push_back(ans);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (safe(visited, i, y, n)) {
            visited[i][y] = 1;
            ans.push_back(i);
            solve(visited, ans, res, y + 1, n);
            ans.pop_back();
            visited[i][y] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    if(n==1 || n==2)
    {
        cout << 1 <<endl;
        return 0;
    }
    else if(n==3)
    {
         cout << "No solution exist" << endl;
         return 0;
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<int> ans;
    vector<vector<int>> res;
    solve(visited, ans, res, 0, n);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
