class Solution {
public:
    int minSteps(string s, string t) 
    {
        int ans =0;
        unordered_map<char,int> um;
        for(char& ch: s)um[ch]++;
        
        for(char&ch: t)
        {
            if(um[ch]!=0){um[ch]--;if(um[ch]==0)um.erase(ch);}
            else ans++;   
        }
        
        for(auto& it:um)ans+=it.second;
        
        return ans/2;
    }
};