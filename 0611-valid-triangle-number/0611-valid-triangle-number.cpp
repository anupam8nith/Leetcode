// #pragma GCC optimize("O3")
class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        int ans = 0, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = n-1; i >= 0; i--) {
            int lo = 0, hi = i-1;
            
            while (lo < hi) {
                if (nums[lo] + nums[hi] > nums[i]) {
                    ans += hi - lo;
                    hi--;
                }
                
                else lo++;
            }
        }
        
        return ans;
    }
};