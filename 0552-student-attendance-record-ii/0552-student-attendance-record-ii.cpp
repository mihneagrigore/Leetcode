#define MOD 1000000007LL

class Solution {
public:
    int checkRecord(int n) {
        long long dp[100005][2][3] = {0};
        dp[1][0][0] = 1;
        dp[1][1][0] = 1;
        dp[1][0][1] = 1;

        for(int i = 2; i <= n; ++i) {
            dp[i][0][0] = (dp[i-1][0][0] % MOD + dp[i-1][0][1] % MOD + dp[i-1][0][2]  % MOD) % MOD ;
            dp[i][1][0] = (dp[i-1][1][0] % MOD + dp[i-1][0][0] % MOD + dp[i-1][0][1] % MOD + dp[i-1][1][1] % MOD + dp[i-1][0][2] % MOD + dp[i-1][1][2] % MOD) % MOD ;
            dp[i][0][1] = (dp[i-1][0][0] % MOD);
            dp[i][1][1] = (dp[i-1][1][0] % MOD);
            dp[i][0][2] = (dp[i-1][0][1] % MOD);
            dp[i][1][2] = (dp[i-1][1][1] % MOD); 
        }

        return (dp[n][0][0] % MOD  
                 + dp[n][1][0] % MOD
                 + dp[n][0][1] % MOD 
                 + dp[n][1][1] % MOD 
                 + dp[n][0][2] % MOD 
                 + dp[n][1][2]% MOD ) % MOD;
    }
};