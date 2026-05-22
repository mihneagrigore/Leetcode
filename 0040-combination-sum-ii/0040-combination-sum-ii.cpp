class Solution {
public:

    vector<vector<int>> result;

    int sum(vector<int> &v) {
        int sum = 0;
        for(int x : v)
            sum += x;
        return sum;
    }

    bool check(vector<int> &sol) {
        for(int i = 0; i < sol.size() - 1; ++i)
            if(sol[i] > sol[i+1])
                return false;
        return true;
    }

    void bkt(int start, int target, vector<int>& v, vector<int>& sol) {

        if(target == 0) {
            result.push_back(sol);
            return;
        }

        for(int i = start; i < v.size(); ++i) {

            if(i > start && v[i] == v[i-1])
                continue;

            if(v[i] > target)
                break;

            sol.push_back(v[i]);

            bkt(i + 1, target - v[i], v, sol);

            sol.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // if(candidates.size() == 1 && candidates[0] == target) {
        //     vector<vector<int>> res(1, vector<int>(1, target));
        //     return res;
        // }

        result.clear();

        sort(candidates.begin(), candidates.end());

        vector<int> sol;
        
        bkt(0, target, candidates, sol);

        return result;
    }
};