
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


//
// vector<int> dp;
// for (auto n : nums)
// {
//     auto iter = lower_bound(begin(dp), end(dp), n);
//     if (iter == end(dp))
//     {
//         dp.push_back(n);
//         continue;
//     }
//     if (*iter > n)
//         *iter = n;
// }
// return dp.size();