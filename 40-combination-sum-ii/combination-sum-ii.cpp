class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int idx, int left, vector<int>& combination) {
        if (left < 0) 
            return;
        else if (left == 0) 
            ans.push_back(combination);
        else {
            for (int i = idx; i < candidates.size() && left >= candidates[i]; i++) {
                if (i > idx && candidates[i] == candidates[i - 1])
                    continue;

                combination.push_back(candidates[i]);
                solve(candidates, i +1 , left-candidates[i], combination);
                combination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, combination);

        return ans;
    }
};