class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) { 
            int profit = 0;
            for (int i = 1; i < n; i++)
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            return profit;
        }
        
        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1,0);
        for (int p=0;p<n;p++) {
            int price = prices[p];
            for (int i = 1; i <= k && i <=p+1; i++) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};