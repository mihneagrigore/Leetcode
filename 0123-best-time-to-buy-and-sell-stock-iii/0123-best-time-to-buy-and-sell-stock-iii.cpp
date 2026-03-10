#include <limits.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int dp[3][100005] = {0};

        for(int k = 1; k < 3; k++) {
            int minim = prices[0];
            for(int i = 1; i < prices.size(); i++) {
                minim = min(minim, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - minim);
            }
        }

        return dp[2][prices.size() - 1];
    }
};