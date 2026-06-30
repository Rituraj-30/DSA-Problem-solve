class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board) {
        for (int i = 0; i < n; i++)
            if (board[row][i] == 'Q')
                return false;

        for (int i = 0; i < n; i++)
            if (board[i][col] == 'Q')
                return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        for (int i = row, j = col; i >= 0 && j < n  ; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void NQueen(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, n, board)) {
                board[row][i] = 'Q';
                NQueen(row + 1, n, board, ans);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        NQueen(0, n, board, ans);

        return ans;
    }
};