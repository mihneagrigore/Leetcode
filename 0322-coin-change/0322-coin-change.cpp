#include <limits.h>

class Solution {

private:
    vector<long long> dp;

public:
    int coinChange(vector<int>& coins, int amount) {
        
        dp.resize(amount + 1, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());

        for(int i = 0; i < coins.size(); ++i) {
            for(int j = 0; j < amount; ++j) {
                if((long long)j + coins[i] > (long long)amount)
                    continue;
                if(dp[j] != INT_MAX)
                    dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
            }
        }

        if(dp[amount] == INT_MAX)
            return -1;

        return dp[amount];
    }
};