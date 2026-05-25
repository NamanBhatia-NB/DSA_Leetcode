class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> s;

        for(char c : password){
            s.insert(c);
        }
        int ans = 0;
        for(char c : s){
            if((c-'0')>=0 && (c-'0')<=9)
                ans+=3;
            else if((c-'a')>=0 && (c-'z')<=0){
                ans +=1;
            }
            else if((c-'A')>=0 && (c-'Z')<=0){
                ans+=2;
            }
            else{
                ans+=5;
            }
            cout<<ans<<" ";
        }

        return ans;
    }
};