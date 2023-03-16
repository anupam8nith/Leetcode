class Solution 
{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        int n= size(nums);
        
        sort(nums.begin(),nums.end()); long long count=0;
        
        for(int i=0;i<n;i++)
        {
            int low = lower-nums[i], high = upper-nums[i];
            
            auto lptr = lower_bound(nums.begin()+i+1,nums.end(),low);
            auto hptr = upper_bound(nums.begin()+i+1,nums.end(),high);
                
            count+= hptr-lptr;
            
        }
        
        return count;
        
    }
};