class Solution {
public:
    bool pot_pune(vector<vector<char>> &board, int lin , int col, int x)
    {
      
        char c=x+'0';
        for(int i=0;i<9;i++)
            {if(board[lin][i]==c) return false; //linie
            if(board[i][col]==c) return false; //col
            }
        //pt patrat 
        int xi=lin/3*3;
        int xj=col/3*3;
        for(int i=xi;i<xi+3;i++)
            for(int j=xj;j<xj+3;j++)
                if(board[i][j]==c)
                    return false;
        return true; 
    }
    bool bkt(vector<vector<char>>& board, int lin, int col)
    {
        if(lin==9)
            return true;
        if(col==9)
            return bkt(board,lin+1,0);
        if(board[lin][col]=='.')
        {
            for(int i=1;i<=9;i++){

                if(pot_pune(board,lin,col,i))
                    {
                        board[lin][col]=i+'0';
                        if(bkt(board,lin,col+1))
                            return true;
                        board[lin][col]='.';
                    }  
            }
            return false;
        } else {
            return bkt(board,lin,col+1);
        }

    }
    void solveSudoku(vector<vector<char>>& board) {
        bkt(board, 0, 0);
    }
};