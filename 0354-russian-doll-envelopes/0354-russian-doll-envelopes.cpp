#include <limits.h>

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        int k = 0;
        for(auto x : envelopes) {
            cout<<"i= "<<k++<<" | "<<x[0]<<" "<<x[1]<<"\n";
        }

        vector<int> lis;

        for(auto x : envelopes) {
            auto pos = lower_bound(lis.begin(), lis.end(), x[1]);

            if(pos == lis.end())
                lis.push_back(x[1]);
            else 
                *pos = x[1];
        }

        return lis.size();
    }
};