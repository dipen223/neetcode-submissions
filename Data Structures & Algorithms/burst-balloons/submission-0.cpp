class Solution {
public:
    int helper(vector<int>& a, int l, int r, vector<vector<int>>& memo) {
        if (l + 1 == r) return 0;                 // no balloons between the walls
        if (memo[l][r] != -1) return memo[l][r];

        int best = 0;
        for (int k = l + 1; k < r; k++) {         // k = LAST balloon burst in (l, r)
            int coins = a[l] * a[k] * a[r]        // neighbors are the walls
                      + helper(a, l, k, memo)     // clear left side first
                      + helper(a, k, r, memo);    // clear right side first
            best = max(best, coins);
        }
        return memo[l][r] = best;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> a = {1};
        for (int x : nums) a.push_back(x);
        a.push_back(1);

        int n = a.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return helper(a, 0, n - 1, memo);
    }
};