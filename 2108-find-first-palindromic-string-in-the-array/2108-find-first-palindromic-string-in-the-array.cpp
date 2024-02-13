class Solution {
public:
    bool isPalindrome(string & s)
    {
        int l =0,h=s.size()-1;
        
        while(l<h) if(s[l++]!=s[h--]) return false;
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) 
    {
        for(string& s: words)
            if(isPalindrome(s)) return s;
        
        return "";
    }
};