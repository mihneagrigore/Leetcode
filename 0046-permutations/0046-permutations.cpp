class Solution {
public:

    bool check(vector<int> &solution) {
        return true;
    }

    void back(vector<vector<int>> &solution, vector<int> &result, vector<int> domain) {
        if(domain.size() == 0 && check(result))
            solution.push_back(result);;
    
        for(int i = 0; i < domain.size(); ++i) {
            vector<int> result_aux(result);
            vector<int> domain_aux(domain);

            result_aux.push_back(domain[i]);
            domain_aux.erase(domain_aux.begin() + i);

            back(solution, result_aux, domain_aux);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;

        vector<int> result;
        
        back(solution, result, nums);

        return solution;
    }
};