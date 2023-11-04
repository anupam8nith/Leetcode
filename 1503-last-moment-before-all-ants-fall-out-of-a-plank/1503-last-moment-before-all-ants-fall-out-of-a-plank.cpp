class Solution 
{
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int ans=0;
        
        for(auto &it:left)ans=max(it,ans);
        for(auto &it:right)ans=max(n-it,ans);
        
        return ans;
    }
};