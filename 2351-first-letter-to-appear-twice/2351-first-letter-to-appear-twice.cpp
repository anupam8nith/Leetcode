class Solution {
public:
    char repeatedCharacter(string s) 
    {
        unordered_map<char,int> um;
        
        for(auto&ch :s)
        {
            um[ch]++;
            if(um[ch]>1) return ch;
        }
        
        return 'a';
    }
};