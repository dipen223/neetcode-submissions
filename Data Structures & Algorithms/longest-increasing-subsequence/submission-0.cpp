class Solution {
   public:
    int longestCommonSubsequence(vector<int>& nums1, vector<int>& nums2, int i, int j,
                                 vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (nums1[i - 1] == nums2[j - 1]) {
            return dp[i][j] = 1 + longestCommonSubsequence(nums1, nums2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(longestCommonSubsequence(nums1, nums2, i, j - 1, dp),
                              longestCommonSubsequence(nums1, nums2, i - 1, j, dp));
    }
    int lengthOfLIS(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> nums2(set.begin(), set.end());
        sort(nums2.begin(), nums2.end());
        int n = nums.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return longestCommonSubsequence(nums, nums2, n, m, dp);
    }
};
