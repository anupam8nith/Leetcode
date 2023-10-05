class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        // ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n =nums.size();
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        int res = nums[0] + nums[1] + nums[2];
        
        if(target <= res)return res;
        
        if(nums[n-1] + nums[n-2] + nums[n-3] <= target) return nums[n-1] + nums[n-2] + nums[n-3];
        
        vector<pair<int,int>> ans;
        
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(abs(sum-target) < abs(res-target)) res = sum;
                
                if(sum < target)j++;
                else k--;
            }
        }
        
        return res;
    }
};