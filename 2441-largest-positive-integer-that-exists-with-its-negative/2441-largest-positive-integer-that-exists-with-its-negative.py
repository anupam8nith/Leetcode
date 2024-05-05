class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        hashmap = Counter(nums)
        
        ans = -1
        for num in nums:
            if -num in hashmap:
                ans = max(ans,num)
                
        return ans