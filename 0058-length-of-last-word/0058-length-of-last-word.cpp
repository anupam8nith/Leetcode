class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int ans = 0, n = size(s)-1;
        
        while(n>=0)
        {
            if(s[n--]!=' ')
                ans++;
            else if(ans!=0) break;
        }
        
        return ans;
    }
};