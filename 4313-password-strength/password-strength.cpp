class Solution {
public:
    int passwordStrength(string password) {
        vector<bool> upper(26, false);
        vector<bool> lower(26, false);
        vector<bool> num(10, false);
        unordered_set<char> spl;

        int ans = 0;
        for (char c : password) {
            if (c >= '0' && c <= '9') {
                if (!num[c - '0']) {
                    num[c - '0'] = true;
                    ans += 3;
                }
            } else if (c >= 'a' && c <= 'z') {
                if (!lower[c - 'a']) {
                    lower[c - 'a'] = true;
                    ans += 1;
                }
            } else if (c >= 'A' && c <= 'Z') {
                if (!upper[c - 'A']) {
                    upper[c - 'A'] = true;
                    ans += 2;
                }
            } else if (!spl.count(c)) {
                spl.insert(c);
                ans += 5;
            }
        }

        return ans;
    }
};