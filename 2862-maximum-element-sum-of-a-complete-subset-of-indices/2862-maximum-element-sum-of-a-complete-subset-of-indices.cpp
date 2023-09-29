class Solution {
public:
    long long maximumSum(vector<int>& nums) 
    {
        long long ans = 0;
        
        for (int key = 1; key <= nums.size(); key++)
            for (long long cur_sum = 0, idx = 1; idx * idx * key <= nums.size(); idx++)
                ans = max(ans, cur_sum += nums[idx * idx * key - 1]);
        
        return ans;
    }
};
