class Solution {
public:
    bool isSafe(int row, int col, char dig, vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == dig)
                return false;
                
            if (board[i][col] == dig)
                return false;
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;

        for(int i=sr;i<=sr+2;i++){
            for(int j=sc;j<=sc+2;j++){
                if(board[i][j]==dig) return false;
            }
        }
        return true;
    }

    bool solver(int row, int col, vector<vector<char>>& board) {
        if (row == 9) {
            return true;
        }

        int nextRow = row, nextCol = col+1 ;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }
        if (board[row][col] != '.') {
            return solver(nextRow, nextCol, board);
        }
        for (char i = '1'; i <= '9'; i++) {
            if (isSafe(row, col, i, board)) {
                board[row][col] = i;
                if (solver(nextRow, nextCol, board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {

        bool istrue = solver(0, 0, board);

    }
};