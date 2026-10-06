class Solution {
public:
    int coinChangeHelper(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(amount < 0 || i == coins.size()) return 0;
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }


        return dp[i][amount] =  coinChangeHelper(i,amount-coins[i],coins,dp)+ 
        coinChangeHelper(i+1,amount,coins,dp);

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return coinChangeHelper(0,amount,coins,dp);




        
    }
};
