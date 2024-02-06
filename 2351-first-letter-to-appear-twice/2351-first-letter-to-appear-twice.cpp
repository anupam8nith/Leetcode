class Solution {
public:
    char repeatedCharacter(string s) 
    {
        vector<int>um(26);
        
        for(auto&ch :s)
        {
            um[ch-'a']++;
            if(um[ch-'a']==2) return ch;
        }
        
        return 'a';
    }
};