class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> um;
        
        for(auto &it: s)um[it]++;
        
        for(auto &ch: t)
        {
            um[ch]--;
            if(um[ch]==0)um.erase(ch);
        }
        
        return um.empty();
    }
};