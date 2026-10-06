class Solution {
public:
    int maxProfitHelper(vector<int>&prices,int i,vector<vector<int>>&dp,int buy){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        if(buy == 1) {
            return dp[i][buy] = max(-prices[i] + maxProfitHelper(prices,i+1,dp,0),maxProfitHelper(prices,i+1,dp,1));
        }else{
            return dp[i][buy] = max(prices[i] + maxProfitHelper(prices,i+2,dp,1),maxProfitHelper(prices,i+1,dp,0));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxProfitHelper(prices,0,dp,1);
    }
};
