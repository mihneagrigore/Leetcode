class Solution {

private:
    vector<int> dp, prev; 

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            dp.resize(nums.size(), 0);
            for(int i = 0; i < nums.size(); ++i) {
                prev.push_back(-1);
            }

            for(int i = 0; i < nums.size(); ++i)
                for(int j = i + 1; j < nums.size(); ++j) {
                    if(nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1) {
                        dp[j] = dp[i] + 1;
                        prev[j] = i;
                    }
                }


            int maxdp = -1, maxpos = -1;
            for(int i = 0; i < nums.size(); ++i)
                if(maxdp < dp[i]) {
                    maxdp = dp[i];
                    maxpos = i;
                }

            cout<<maxpos<<"\n";

            for(int i = 0; i < nums.size(); ++i)
                cout<<dp[i] << " ";

            cout<<"\n";

            for(int i = 0; i < nums.size(); ++i)
                cout<<prev[i] << " ";

            vector<int> res;
            while(prev[maxpos] != -1) {
                res.insert(res.begin(), nums[maxpos]);
                maxpos = prev[maxpos];
            }

            res.insert(res.begin(), nums[maxpos]);

            return res;
    }
};