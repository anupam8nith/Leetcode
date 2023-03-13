class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count=0, prefixsum=0;
        
        map<int,int> mp;
        mp[0]=1;
        
        for(auto it: nums)
        {
            prefixsum += it;
            count += mp[prefixsum - k];
            mp[prefixsum]++;
        }
        
        return count;
        
    }
};