class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> mx(n);
        mx[n-1] = nums[n-1];
        using ll = long long;
        ll re =0;
        for(int i=n-2;i>=0;i--) mx[i] = max(mx[i+1],nums[i]);
        int mi = nums[0];
        for(int i=1;i+1<n;i++){
            mi=max(mi,nums[i-1]);
            if(nums[i] < mi) re=max(re,(mi-nums[i]) * (ll)mx[i+1]);
        }
        return re;
    }
};