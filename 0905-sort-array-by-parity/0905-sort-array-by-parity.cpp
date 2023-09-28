class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        vector<int> ans;
        
        for(int it: nums)if(!(it&1))ans.push_back(it);
        
        for(int it: nums)if(it&1)ans.push_back(it);
        
        return ans;
        
    }
};