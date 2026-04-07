#include <cstring>

class Solution {
public:

    bool back(vector<vector<char>> &domain, string word, int i, int j, int k) {

        if(k == word.size())
            return true;

       if(i < 0 || j < 0 || i >= domain.size() || j >= domain[i].size())
        return false;

        if(domain[i][j] != word[k])
            return false;

             char tmp = domain[i][j];
             domain[i][j] = '#';
             int ok = back(domain, word, i+1, j, k+1) ||
                        back(domain, word, i-1, j, k+1) ||  
                        back(domain, word, i, j + 1, k+1) ||
                        back(domain, word, i, j - 1, k+1);
            domain[i][j] = tmp;

            if(ok)
                return true;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) 
            for(int j = 0; j < board[i].size(); ++j)
                if(back(board, word, i, j, 0))
                    return true;

        return false;
    }
};