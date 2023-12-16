from collections import Counter
class Solution(object):
    def isAnagram(self, s, t):
        
        if len(s)!=len(t):
            return False;
            
        mp1 = Counter(s)
        
        for ch in t:
            mp1[ch]-=1
            if mp1[ch]==0:
                del mp1[ch]
                
        
        return len(mp1)==0
        
        