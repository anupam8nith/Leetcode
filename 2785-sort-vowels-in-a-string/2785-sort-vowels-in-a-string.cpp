class Solution {
public:
    string sortVowels(string s) 
    {
        string ans = s, vowels=""; vector<int> pos;
        
        for(int i=0;i<s.size();i++) 
        {
            char c= s[i];
            bool isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            bool isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
            if(isLowercaseVowel || isUppercaseVowel) {pos.push_back(i); vowels+=c;}
        }
        
        sort(vowels.begin(),vowels.end());
        
        for (int j = 0; j < pos.size(); j++) ans[pos[j]] = vowels[j];
        
        return ans;
    }
};