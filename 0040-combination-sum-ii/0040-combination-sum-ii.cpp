class Solution {
public:

    bool check(vector<int> result, int target) {

        if(target == 0)
            return true;
        
        return false;
    }

    void back(vector<vector<int>> &solution, vector<int> &result, vector<int> &domain, int target, int start)
    {
        if(check(result, target)) {
            solution.push_back(result);
            return;
        }

        for(int i = start; i < domain.size(); ++i) {

            if(domain[i] > target)
                break;

            if(i > start && domain[i] == domain[i-1])
                continue;

            result.push_back(domain[i]);

            back(solution, result, domain, target - domain[i], i+1);

            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector <int>> solution;
        vector<int> result;

        sort(candidates.begin(), candidates.end());

        back(solution, result, candidates, target, 0);

        return solution;
    }
};