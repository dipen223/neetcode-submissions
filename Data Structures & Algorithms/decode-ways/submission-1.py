import string

class Solution:
    def ways(self, i, s, codes,memo):
        if i == len(s):
            return 1
        if memo[i] != -1:
            return memo[i]
        count = 0
        if s[i] in codes:
            count += self.ways(i + 1, s, codes,memo)
        if i + 1 < len(s) and s[i:i+2] in codes:
            count += self.ways(i + 2, s, codes,memo)
        memo[i] = count
        return count

    def numDecodings(self, s: str) -> int:
        n = len(s)
        codes = {str(i): ch for i, ch in enumerate(string.ascii_uppercase, start=1)}
        memo = [-1]*n
        return self.ways(0, s, codes,memo)
