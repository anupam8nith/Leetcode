class Solution {
public:
    int rev(int n)
    {
        int reversed=0;
        while(n>0)
        {
            reversed*=10;
            reversed+=n%10;
            n/=10;
        }
        return reversed;
    }
    
    int countNicePairs(vector<int>& nums) 
    {
        int mod = 1e9+7, ans=0;
        unordered_map<int,int> revdiff;
        
        for(auto& it: nums) ans = (ans + revdiff[it-rev(it)]++)%mod;
        
        return ans; 
    }
};