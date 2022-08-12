class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int low=0,high = nums.size(), mid;
        
        while(low<high)
        {
            mid = low + (high-low)/2;
            
           if(target<= nums[mid])
           {
               high = mid;
           }
            else
            {
                low = mid+1;
            }
        }
        
        if(target>nums[nums.size()-1] && low!=nums.size())
        {
            low++;
        }
        
        return low;
    }
};