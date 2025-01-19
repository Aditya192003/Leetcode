class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.')); // Initialize board with '.'
        vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
        backtrack(0, n, board, results, cols, diag1, diag2);
        return results;
    }
    
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& results,
                   vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            results.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;

            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;

            backtrack(row + 1, n, board, results, cols, diag1, diag2);

            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
};
