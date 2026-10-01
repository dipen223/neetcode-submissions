class Solution {
public:
    int coinChangeHelper(int i, vector<int>& coins, int amount, vector<vector<int>>& memo) {
        if (amount == 0) return 0;
        if (i == coins.size() || amount < 0) return INT_MAX;
        if (memo[i][amount] != -1) return memo[i][amount];

        int take = coinChangeHelper(i, coins, amount - coins[i], memo);
        if (take != INT_MAX) take += 1;
        int skip = coinChangeHelper(i + 1, coins, amount, memo);

        return memo[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        int res = coinChangeHelper(0, coins, amount, memo);
        return res == INT_MAX ? -1 : res;
    }
};