from collections import Counter
class Solution(object):
    def isAnagram(self, s, t):
        mp1 = Counter(s)
        mp2= Counter(t)
        
        if len(mp1)!=len(mp2):
            return False
        
        for char,freq in mp1.items():
            if freq!=mp2[char]:
                return False
        
        return True;
        
        