class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string s1="",s2="";int n1 = word1.size(), n2 = word2.size();
        
        for(string str: word1)s1+=str; for(string str: word2)s2+=str;
        
        if(s1.size()!=s2.size()) return false;
        
        for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i]) return false;
        
        return true;
    }
};