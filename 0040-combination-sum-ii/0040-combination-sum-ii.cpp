class Solution {
public:

    vector<vector<int>> result;

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
        sort(candidates.begin(), candidates.end());

        vector<int> sol;
        
        bkt(0, target, candidates, sol);

        return result;
    }
};