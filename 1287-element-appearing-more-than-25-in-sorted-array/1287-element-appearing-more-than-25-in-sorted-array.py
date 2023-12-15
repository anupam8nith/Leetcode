from collections import Counter

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)//4
        elementCount= Counter(arr)
        
        for num,freq in elementCount.items():
            if freq>n:
                return num