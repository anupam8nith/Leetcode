class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i && nums[i] < n) 
            {
                if (nums[i] == nums[nums[i]]) break;
                swap(nums[i], nums[nums[i]]);
            }
        }
        
        for (int i = 0; i < n; ++i)
            if (nums[i] != i) return i;
        
        return n;
    }
};