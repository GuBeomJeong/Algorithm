# 풀이1
각 주식마다 모든 트랜잭션의 값을 구하는 방식   

```c++
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
```
> Runtime: 500 ms, faster than 18.55% of C++ online submissions for Best Time to Buy and Sell Stock IV.
Memory Usage: 14.7 MB, less than 9.66% of C++ online submissions for Best Time to Buy and Sell Stock IV.
(좀 이상)