class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int ans = 0, n = size(s)-1;
        
        while(s[n]==' ')n--;
        while(n>=0 && s[n--]!=' ')ans++;
        
        return ans;
            
    }
};