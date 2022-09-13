class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n);
        if(n==1)
        {
            ans[0]=-1;
            return ans;
        }
        
        for(int i=0;i<n;i++)
        {
                if(nums[(i+1)%n]>nums[i])
                {
                    ans[i]=nums[(i+1)%n];
                }
                else
                {
                    int j=i+1,count=0;
                    
                    while(count<n-1)
                    {
                        if(nums[(j+1)%n]>nums[i])
                        {
                            ans[i]=nums[(j+1)%n];
                            break;
                        }  
                        j++;
                        count++;
                    }
                    if(count==n-1)
                        ans[i]=-1;
                    
                }
            
        }
        
        return ans;
        
    }
};