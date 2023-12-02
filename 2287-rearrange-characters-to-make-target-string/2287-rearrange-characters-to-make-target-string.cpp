class Solution {
public:
    int rearrangeCharacters(string s, string target) 
    {
        int count1[26]{}; int count2[26]{};
        for(char& ch: s)count1[ch-'a']++;
        
        for(char& ch: target)count2[ch-'a']++;
        
        for(int i=0; i<26; i++)if(count2[i])count1[i]/=count2[i];
        
        int ans = INT_MAX;
        for(char& ch: target)ans = min(ans, count1[ch-'a']);
        
        return ans;
    }
};