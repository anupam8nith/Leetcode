
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        
     int mntill= INT_MAX, btwn = INT_MAX, n=nums.size();
        if(n<=2)
            return false;
        
            
        for(int i=0;i<n;i++)
        {
            if(nums[i]>btwn)
                return true;

            else if(nums[i] > mntill && nums[i] < btwn)
                btwn =nums[i];   
            
            else if(nums[i] < mntill)
               mntill = nums[i];
            
        }
        
        return false;
        
    }
};