class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;
        int bestBuy = prices[0];

        for(int i=1; i<prices.size(); i++){
            profit = prices[i] - bestBuy;
            maxProfit = max(profit,maxProfit);
            if(prices[i] < bestBuy){
                bestBuy = prices[i];
            }
        }

        return maxProfit;
    }
};
