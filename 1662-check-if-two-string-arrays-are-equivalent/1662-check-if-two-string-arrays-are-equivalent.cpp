class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        
        string s1="",s2="";int n1 = word1.size(), n2 = word2.size();
        
        int i=0,j=0, equal_idx=0;
        while(true)
        {
            if(i<n1)
            s1+=word1[i++];
            if(j<n2)
            s2+=word2[j++];
            
            if(s1.size()==s2.size())
            {
                for(int i=equal_idx;i<s1.size();i++)if(s1[i]!=s2[i])return false;
                
                equal_idx=s1.size();
            }
            
            if(i==n1 && j==n2)break;
        }
        
        if(s1.size()!=s2.size()) return false;
        
        for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i]) return false;
        
        return true;
    }
};