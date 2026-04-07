class Solution {
public:
    bool good(const vector<vector<char>> &board, int i, int j) {
        char val = board[i][j];

        for(int k = 0; k < 9; ++k)
            if (k != i && board[k][j] == val)
                return false;

        for(int k = 0; k < 9; ++k)
            if (k != j && board[i][k] == val)
                return false;

        int sqi = 3 * (i / 3);
        int sqj = 3 * (j / 3);

        for(int k = 0; k < 3; ++k)
            for(int q = 0; q < 3; ++q)
                if ((sqi + k != i || sqj + q != j) && board[sqi + k][sqj + q] == val)
                    return false;

        return true;
    }

    bool bkt(vector<vector<char>> &board, int i, int j) {
        if(i == 9) return true;          
        if(j == 9) return bkt(board, i + 1, 0);

        if(board[i][j] != '.') 
            return bkt(board, i, j + 1);  

        for(char c = '1'; c <= '9'; ++c) {
            board[i][j] = c;
            if(good(board, i, j) && bkt(board, i, j + 1))
                return true;              
            board[i][j] = '.';          
        }

        return false;                    
    }

    void solveSudoku(vector<vector<char>>& board) {
        bkt(board, 0, 0);
    }
};