class Solution {
public:

    int min(int a, int b) {
        if(a < b)
            return a;
        return b;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        priority_queue<pair<int, int>> q;

        for(int i = 0; i < min(k, nums.size()); i++)
            q.push({nums[i], i});

        result.push_back(q.top().first);

        for(int i = k; i < nums.size(); i++) {
            q.push({nums[i], i});
            
            while(q.top().second <= i - k)
                q.pop();

            result.push_back(q.top().first);
        }

        return result;
    }
};