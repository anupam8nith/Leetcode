class Solution {
public:
    Solution()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    }
    
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        vector<int> x(points.size()); int ans=0;
        
        for(int i=0;i<points.size();i++)x[i]=points[i][0];
        
        sort(x.begin(),x.end());
        
        for(int i=0;i<x.size()-1;i++) ans = max(ans,x[i+1]-x[i]);
        
        return ans;
    }
};