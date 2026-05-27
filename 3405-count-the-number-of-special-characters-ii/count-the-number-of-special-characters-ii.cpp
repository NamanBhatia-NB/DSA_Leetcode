class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLow(26, -1);
        vector<int> firstUp(26, -1);
        int ans = 0;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (islower(ch)) {
                lastLow[ch - 'a'] = i;
            } else if (firstUp[ch - 'A'] == -1) {
                firstUp[ch - 'A'] = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i])
                ans++;
        }

        return ans;
    }
};