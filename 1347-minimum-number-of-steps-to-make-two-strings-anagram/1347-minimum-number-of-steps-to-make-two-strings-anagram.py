class Solution:
    def minSteps(self, s: str, t: str) -> int:
        freqS = Counter(s)
        ans = 0
        
        for ch in t:
            if freqS[ch]!=0:
                freqS[ch]-=1
            else :
                ans += 1
        for i in freqS.values():
            ans+=i
        
        return ans//2;
            