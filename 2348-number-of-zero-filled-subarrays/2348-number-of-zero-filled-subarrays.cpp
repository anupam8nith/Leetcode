class Solution 
{
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        int n = nums.size(); long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)continue;
            
            int count=0;
            while(nums[i]==0 && i<n-1) 
            {
                // cout<<i<<endl;
                count++;i++;
            }
            
             if(i==n-1 && nums[n-1]==0) count++; 
            
            // cout<<count<<endl;
            
            ans+= (long long)count*(count+1)/2;
        
        }
        
        return ans;
        
    }
};