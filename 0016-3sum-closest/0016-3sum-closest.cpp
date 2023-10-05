class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(0);
        int n =nums.size();
        sort(nums.begin(),nums.end());
        
        vector<pair<int,int>> ans;
        
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k],diff= abs(target-sum);
                if(diff==0) return sum;
                else if(sum<target)
                {
                    ans.push_back({diff,sum});
                    j++;
                }
                else
                {
                    ans.push_back({diff,sum});
                    k--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans[0].second;
    }
};