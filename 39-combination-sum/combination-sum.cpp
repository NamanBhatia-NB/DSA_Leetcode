class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, int sum, vector<int> &combination, vector<vector<int>>& ans) {
        if(sum==target){
            ans.push_back(combination);
            return;
        }

        if( i >= candidates.size() || sum>target){
            return;
        }

        // include
        combination.push_back(candidates[i]);
        solve(candidates, target, i, sum + candidates[i], combination, ans);

        // exclude
        combination.pop_back();
        solve(candidates, target, i + 1, sum, combination, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        solve(candidates, target, 0, 0, combination, ans);

        return ans;
    }
};