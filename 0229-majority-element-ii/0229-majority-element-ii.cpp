class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();vector<int> ans;unordered_map<int,int> um;
        
        for(auto it: nums)um[it]++;
        
        for(auto it: um)if(it.second>n/3) ans.push_back(it.first);
        
        return ans;
    }
};