class Solution {
public:
    bool find(vector<vector<char>>& board, string & word , int row,int col,int idx){

        if(idx==word.size()) return true;
        if(row<0 ||row>=board.size() 
        || col<0 || col>=board[0].size() || 
        board[row][col]!=word[idx] ) return false;

        char ch=board[row][col];
        board[row][col]='*';

        bool found=( find(board,word,row+1,col,idx+1)||find(board,word,row-1,col,idx+1)||
                    find(board,word,row,col+1,idx+1) || find(board,word,row,col-1,idx+1));

        board[row][col]=ch;

        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && find(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};