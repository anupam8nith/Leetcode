class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int valueDiff) 
    {
        set<int> bag;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i>k)bag.erase(nums[i-k-1]);
            
            auto pos = bag.lower_bound(nums[i]-valueDiff);
            
            if(pos!=bag.end() && *pos-nums[i]<=valueDiff) return true;
            
            bag.insert(nums[i]);
        }
        
        return false;
        
    }
};