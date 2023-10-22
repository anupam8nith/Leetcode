class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
       int i = k - 1, j = k + 1, n = nums.size(), res = nums[k], mn = nums[k];
        
        while (i >= 0 || j < n) 
        {
            if (i < 0 || (j < n && nums[j] > nums[i])) 
            {
                mn = min(mn, nums[j]);
                ++j;
            } 
            else 
            {
                mn = min(mn, nums[i]);
                --i;
            }
            res = max(res, mn * (j - i - 1));
        }
        return res;
    }
};