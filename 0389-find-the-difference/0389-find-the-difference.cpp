class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        char c = 0; s+=t;
        
        for(char cs : s) c ^= cs;
        return c;
        
    }
};