class Solution {
public:
    string sortVowels(string s) 
    {
        string ans = s, vowels=""; vector<int> pos;
        
        for(int i=0;i<s.size();i++) 
        {
            auto c= s[i];
            auto isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            auto isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
            if(isLowercaseVowel || isUppercaseVowel) {pos.push_back(i); vowels+=c;}
        }
        
        sort(vowels.begin(),vowels.end());
        
        int j=0;
        for(auto i: pos)ans[i]=vowels[j++];
        
        return ans;
    }
};