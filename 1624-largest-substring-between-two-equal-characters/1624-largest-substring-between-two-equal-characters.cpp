class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        int ans=-1, n = s.size();vector<int> idx(26,-1);
        
        for(int i=0;i<n;i++)
        {
            if(idx[s[i]-'a']==-1){idx[s[i]-'a']=i;continue;}
            ans = max(ans,abs(i-idx[s[i]-'a']-1));
        }
        
        return ans;
    }
};