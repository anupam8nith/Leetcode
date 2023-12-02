class Solution {
public:
    int rearrangeCharacters(string s, string target) 
    {
        int count[26]{}; int ans=0;
        
        for(char& ch : s) ++count[ch - 'a'];
        
        while(true)
        {
            for(char& ch : target){if(count[ch-'a']>=1)--count[ch-'a'];else return ans;}
            
            ans++;
        }
        
        return ans;
    }
};