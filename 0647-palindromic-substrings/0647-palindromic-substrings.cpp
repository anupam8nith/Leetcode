class Solution {
    bool isPalindrome(string s)
    {
        int l=0, h=s.size()-1;
        
        while(l<h) if(s[l++]!=s[h--]) return false;
        
        return true; 
    }
    
public:
    int countSubstrings(string s) 
    {
        int ans=0;
        
        for(int i=0;i<s.size();i++)
            for(int j=i;j<s.size();j++)
                if(isPalindrome(s.substr(i,j-i+1)))
                    ans++;
        return ans;
    }
};