class Solution:
    def checkStrings(self, s1, s2):
        # Compare even indices
        if sorted(s1[::2]) != sorted(s2[::2]):
            return False
        
        # Compare odd indices
        if sorted(s1[1::2]) != sorted(s2[1::2]):
            return False
        
        return True