class Solution {
public:
    bool interLeaveHelper(string s1,int i,string s2,int j,string s3,vector<vector<int>>&dp){
        if(i == s1.size() && j == s2.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = false;
        if (i < s1.size() && s1[i] == s3[i+j])
            ans = interLeaveHelper(s1, i+1, s2, j, s3, dp);
        if (!ans && j < s2.size() && s2[j] == s3[i+j])
            ans = interLeaveHelper(s1, i, s2, j+1, s3, dp);

        dp[i][j] = ans;
        return ans;

        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return interLeaveHelper(s1,0,s2,0,s3,memo);
        
    }
};
