class Solution {
public:
    // n -> left paranthesis count
    // m -> right paranthesis count
    void solve(vector<string>& ans, string res, int n, int m) {
        if (n == 0 && m == 0) {
            ans.push_back(res);
            return;
        }

        if (n > 0)
            solve(ans, res + '(', n - 1, m + 1);
        if (m > 0)
            solve(ans, res + ')', n, m - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, 0);

        return ans;
    }
};