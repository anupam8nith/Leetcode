class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans; ans+=s[0];

        // Start iterating from the second character of the string
        for (int i = 1; i < n; i++) 
        {
            if (!ans.empty()) 
            {
                char ch = ans.back();

                if (tolower(ch) == tolower(s[i]) && ch != s[i])
                    ans.pop_back();
                else 
                    ans += s[i];
            }
            
            else ans += s[i];
        }
        return ans;
    }
};