class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow =nums[nums[0]], fast = nums[slow];
        
        while(fast!=slow)
        {
            slow = nums[slow];
            fast= nums[nums[fast]];
        }
        
        slow=nums[0];
        
        while(fast!=slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;
    }
};