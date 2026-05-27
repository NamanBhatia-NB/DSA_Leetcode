class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";

        int n = num1.size() + num2.size();

        string ans(n,'0');

        for (int i = num2.size() - 1; i >= 0; i--) {
            int digit2 = num2[i] - '0';
            for (int j = num1.size() - 1; j >= 0; j--) {
                int digit1 = num1[j] - '0';
                int pos = i + j + 1;

                int carry = ans[pos]-'0';
                int mul = digit1*digit2 + carry;

                ans[pos]=(mul%10)+'0';

                ans[pos-1]+=mul/10;
            }
        }

        if(ans[0]=='0')
            ans.erase(0,1);

        return ans;
    }
};