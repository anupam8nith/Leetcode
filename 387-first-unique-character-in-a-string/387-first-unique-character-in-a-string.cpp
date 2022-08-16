class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,int> um1,um2;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            um1[s[i]]++; //freq
            um2[s[i]] = i; //index;
        }
        
        for(auto ch: um1)
        {
            if(ch.second==1)
             return um2[ch.first];
        }
        
        return -1;
        
    }
};