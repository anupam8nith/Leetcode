from collections import Counter

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)//4
        hashmap= Counter(arr)
        
        for num,freq in hashmap.items():
            if freq>n:
                return num