class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0;i<n;i++)
        {
            for(int a=i+1;a<n;a++)
            {
                int j=a+1,k=n-1;
            
            while(j<k)
            {
                long long sum = (long long)nums[i]+ nums[a] + nums[j] + nums[k];
                if(sum==target)
                {
                    s.insert({nums[i],nums[a],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k]==nums[k-1])k--;
                    j++;
                    k--;
                }
                else if(sum<target) j++;
                else k--;  
            }
            }
        }
        
        for(auto it: s)ans.push_back(it);
        
        return ans;
        
    }
};