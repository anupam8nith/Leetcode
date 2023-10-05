class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);cin.tie(0);
        
        int n = nums.size();vector<int> ans;unordered_map<int,int> um;
        
        for(auto it: nums)um[it]++;
        
        for(auto it: um)if(it.second>n/3) ans.push_back(it.first);
        
        return ans;
    }
};