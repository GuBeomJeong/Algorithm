class Solution {
public:
    
    int max(int a,int b){
        return a>b ? a: b;
    }
    
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        
        vector<int> values;
        
        values.push_back(1);
        for(int i=0;i<n;i++){
            values.push_back(nums[i]);
        }
        values.push_back(1);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int len = 1; len <= n; len++){
            for(int start = 1; start<= n - len + 1; start++){
                int end = start + len - 1;
                
                for(int mid = start;mid<=end;mid++){
                    dp[start][end] = max(dp[start][end],dp[start][mid-1] + values[start-1] * values[mid] * values[end+1] + dp[mid+1][end]);
                }
                
            }
        }
        
        return dp[1][n];
    }
};