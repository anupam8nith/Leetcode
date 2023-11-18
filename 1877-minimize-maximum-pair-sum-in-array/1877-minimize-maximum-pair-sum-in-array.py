class Solution(object):
    def minPairSum(self, nums):
        nums.sort()
        n = len(nums)
        ans = float('-inf')
        
        for i in range(n // 2):
            ans = max(nums[i] + nums[n - 1 - i], ans)
            
        return ans
