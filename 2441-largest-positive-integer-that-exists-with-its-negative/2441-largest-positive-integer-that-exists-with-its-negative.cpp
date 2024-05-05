class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        unordered_map<int,int> um; for(int it: nums)um[it]++;
        int ans =-1;
        for(int it: nums)
            if(um[-it])
                ans=max(ans,it);
        
        return ans;
        
    }
};