class Solution {
   public:
    bool isMatchHelper(string &s, string &p, int i, int j,vector<vector<int>>&memo) {
        if (i < 0 && j < 0) return true;
        if (j < 0 ) return false;

        if (memo[i + 1][j + 1] != -1) {
            return memo[i + 1][j + 1];
        }
            
            bool ans = false;

            if (p[j] == '*') {
                ans = isMatchHelper(s, p, i, j - 2,memo) ||
                    (i >= 0 && s[i] == p[j - 1] || p[j - 1] == '.') && isMatchHelper(s, p, i - 1, j,memo);
            } else {
                if (i >= 0 && (s[i] == p[j] || p[j] == '.')) {
                   ans =  isMatchHelper(s, p, i - 1, j - 1,memo);
                }
            }

            return memo[i+1][j+1] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return isMatchHelper(s,p,n-1,m-1,memo);
    }
};
