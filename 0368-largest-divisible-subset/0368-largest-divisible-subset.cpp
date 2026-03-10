class Solution {

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp, prev, res;
        int maxim_dp = 0, idx = 0;
        dp.push_back(1);
        prev.push_back(-1);

        for(int i = 1; i < nums.size(); i++) {
            dp.push_back(1);
            prev.push_back(-1);
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j] + 1)
                        prev[i] = j;
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > maxim_dp) {
                maxim_dp = dp[i];
                idx = i;
            }
        }

        while(idx != -1) {
            res.push_back(nums[idx]);
            idx = prev[idx];
        }

        return res;
    }
};