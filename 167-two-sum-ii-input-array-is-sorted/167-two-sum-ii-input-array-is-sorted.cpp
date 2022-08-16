class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            if(binary_search(nums.begin(), nums.end(),target-*it))
            {
                ans.push_back((it-nums.begin())+1);
                int id = lower_bound(it+1, nums.end(),target-*it) - nums.begin() +1;
                ans.push_back(id);
                break;
            }
        }
        
        return ans;
    }
};