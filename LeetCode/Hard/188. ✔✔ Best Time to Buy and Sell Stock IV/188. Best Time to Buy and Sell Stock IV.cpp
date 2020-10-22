class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<2){
            return 0;
        }
        if (k >= n / 2) { 
            int profit = 0;
            for (int i = 1; i < n; i++)
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            return profit;
        }
        
        int buy[k+1];
        int sell[k+1];
        for(int i=0;i<=k;i++){
            buy[i] = INT_MIN;
            sell[i] = 0;
        }
        int price;
        for (int p=0;p<n;p++) {
            price = prices[p];
            for (int i = 1; i <= k && i <=p+1; i++) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};