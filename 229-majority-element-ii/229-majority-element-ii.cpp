class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
       
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
        vector<int> ans;
        
      unordered_map<int,int> um;
        
        int n= nums.size();
        
        for(int i=0;i<n;i++)
        {
            um[nums[i]]++;
            
            if(um[nums[i]]>floor(n/3))
            {
                if(ans.empty()==1 || find(ans.begin(),ans.end(),nums[i])==ans.end())
                {
                    ans.push_back(nums[i]);
                }
            }
            
            
            }
        return ans;
    }
       
};