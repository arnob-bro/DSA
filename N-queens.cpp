#include <iostream>
#include <vector>

using namespace std;

// Function to print the solution
void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int i, j;
    int n = board.size();

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve N-Queens problem
void solveNQueensUtil(vector<vector<int>>& board, int col, vector<vector<vector<int>>>& solutions) {
    int n = board.size();
    
    // If all queens are placed, add the solution to the list
    if (col >= n) {
        solutions.push_back(board);
        return;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            solveNQueensUtil(board, col + 1, solutions);

            // If placing queen in board[i][col] doesn't lead to a solution, then remove the queen (backtrack)
            board[i][col] = 0;
        }
    }
}

// Function to solve the N-Queens problem and return all solutions
vector<vector<vector<int>>> solveNQueens(int n) {
    // Initialize the board with 0s
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> solutions;

    solveNQueensUtil(board, 0, solutions);

    return solutions;
}

int main() {
    int n = 4; // You can change the value of n to solve for different sizes
    vector<vector<vector<int>>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << endl;
    for (const auto& solution : solutions) {
        printSolution(solution);
    }

    return 0;
}
