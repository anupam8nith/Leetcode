class Solution:
    def maxDifference(self, s: str) -> int:
        freq = Counter(s)
        a1,a2=0,100
        
        for val in freq.values():
            if val&1:
                a1=max(a1,val)
            else:
                a2=min(a2,val)
        return a1-a2
