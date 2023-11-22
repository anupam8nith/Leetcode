class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        cout.tie(0);
        
        map<int,vector<int>> um; vector<int> diag;
        
        for(int i=0;i<nums.size();i++) for(int j=0;j<nums[i].size();j++) um[i+j].push_back(nums[i][j]);
        
        for(auto it: um) for(auto ptr = it.second.rbegin();ptr!=it.second.rend();++ptr) diag.push_back(*ptr);
        
        return diag;
        
    }
};