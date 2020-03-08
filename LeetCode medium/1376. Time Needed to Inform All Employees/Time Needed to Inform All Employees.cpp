class Solution {
public:
    
    int result;
    
    int urgent(int idx, vector<int>& parent, vector<int>& inform, vector<int>& dp){
        
        if(parent[idx] == -1){
            return inform[idx];
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        dp[idx] = urgent(parent[idx],parent,inform,dp) + inform[idx];
        
        if(dp[idx] > result){
            result = dp[idx];
        }
        
        return dp[idx];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        result = 0;
        
        vector<int> dp(n,-1);
        
        for(int i=0;i<n;i++){
            urgent(i,manager,informTime,dp);
        }
        
        return result;
    }
};