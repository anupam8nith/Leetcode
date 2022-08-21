class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int p= s.size();
        int q= t.size();
        
        if(p!=q)
            return false;
        
        unordered_map<char,int> m;
        
        for(int i=0;i<p;i++) m[s[i]]++; //frequency of s
        
        for(int i=0;i<q;i++) m[t[i]]--;
        
        for(int i=0;i<q;i++) 
        {
            if(m[t[i]]!=0)
                return false;
        }
            
        return true;
    }
};