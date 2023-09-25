class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char,int> ums,umt;
        for(auto ch: s)ums[ch]++;
        for(auto ch: t)umt[ch]++;
        
        for(auto ch: t)if(umt[ch]!=ums[ch]) return ch;
        
        
        
        return' ';
        
    }
};