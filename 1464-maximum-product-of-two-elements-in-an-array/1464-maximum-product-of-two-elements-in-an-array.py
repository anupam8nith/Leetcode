class Solution(object):
    def maxProduct(self, nums):
        if len(nums) < 2:
            return -1

        max_element = float('-inf')
        second_max = float('-inf')

        for num in nums:
            if num > max_element:
                second_max = max_element
                max_element = num
            elif num > second_max:
                second_max = num

        return (max_element - 1) * (second_max - 1)
