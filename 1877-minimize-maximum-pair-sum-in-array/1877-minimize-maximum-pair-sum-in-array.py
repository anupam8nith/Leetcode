class Solution(object):
    def minPairSum(self, nums):
        x = sorted(nums)
        return  max(x[-i-1] + x[i] for i in range(len(x)/2))