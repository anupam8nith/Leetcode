class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int ans=0;
        unordered_map<int,int> mp;
        
        for(auto it: nums) mp[it]++;
        
        for(auto &it:mp)
        {
            int frq= it.second;
            if(frq==1) return -1;
            
            ans+= frq/3;
            
            if(frq%3) ans++;
            
        }
        
        return ans;
    }
};