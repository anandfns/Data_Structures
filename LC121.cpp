class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Imagine everday as the selling dy then proceed

        int n = prices.size();
        int maxProfit = 0;
        int bestBuy = prices[0];

        for(int i=1; i<n; i++) { // logic
            if(prices[i] > bestBuy) {
                maxProfit = max(maxProfit , prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy , prices[i]); // to find on which day we should have bought the stock
        }

        return maxProfit;
        
    }
};