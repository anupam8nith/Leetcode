class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n =nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0)
                {
                    s.insert({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k]==nums[k-1])k--;
                    j++;
                    k--;
                }
                else if(sum<0) j++;
                else k--;  
            }
        }
        
        for(auto it: s)ans.push_back(it);
        
        return ans;
        
    }
};