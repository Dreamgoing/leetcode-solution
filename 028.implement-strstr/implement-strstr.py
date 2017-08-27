
class Solution(object):
    def strStr(self, haystack, needle):
        if needle == haystack:
            return 0
        for x in range(len(haystack)):
            if x + len(needle) <= len(haystack) and haystack[x:x + len(needle)] == needle:
                return x
        return -1