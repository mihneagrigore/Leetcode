class Solution {
public:

    bool check(vector<int> solution) {
        for(int i = 0; i + 1 < solution.size(); ++i)
            if(solution[i] >= solution[i+1])
                return false;
        return true;
    }


    void back(vector<vector<int>> &solution, vector<int> &result, int k, int start, vector<int> &domain) 
    {
        if(check(result) && result.size() == k)  {
            solution.push_back(result);
            return;
        }

        for(int i = start; i < domain.size(); i++) {
            int tmp = domain[i];

            result.push_back(domain[i]);

            back(solution, result, k, i+1, domain);

            result.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> solution;
        vector<int> result;


        vector<int> domain;
        for(int i = 1; i <=n; i++)
            domain.push_back(i);

        back(solution, result, k, 0, domain);

        return solution;
    }
};