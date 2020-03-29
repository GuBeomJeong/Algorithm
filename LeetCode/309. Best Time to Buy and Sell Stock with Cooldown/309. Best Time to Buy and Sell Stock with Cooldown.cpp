class Solution {
public:    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sell = 0;
        int save = 0;
        
        for(int i=1; i < n ; i ++){
            int prev = sell;
            sell = max(sell + prices[i] - prices[i-1], save);
            save = max(save, prev);
        }
        
        return max(sell,save);
        
    }
};