class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums:
            return 1

        n = len(nums)
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = n + 1

        for i in range(n):
            a = abs(nums[i])
            if a <= n:
                nums[a - 1] = -abs(nums[a - 1])

        for i in range(n):
            if nums[i] > 0:
                return i + 1

        return n + 1