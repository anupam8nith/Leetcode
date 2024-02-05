class Solution {
public:
    int firstUniqChar(string s) 
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        
        vector<int> freq(26,0);
        
        for(auto& ch: s)freq[ch-'a']++;
        
        for(int i=0;i<s.size();i++)
            if(freq[s[i]-'a']==1) return i;
            
        return -1;
    }
};