class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int dp[n+1][n+1][n+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        
        dp[1][1][1] = grid[0][0];
        
        for(int x1=1; x1 <= n; x1++){
            for(int y1=1;y1<=n;y1++){
               for(int x2=1; x2 <= n;x2++){
                   int y2 = x1 + y1 - x2;
                   
                   if(dp[x1][y1][x2] > 0 || y2 < 1 || y2 > n || grid[x1-1][y1-1] == -1 || grid[x2-1][y2-1] == -1){
                       continue;
                   }
                   
                   int pre = max(max(dp[x1-1][y1][x2],dp[x1][y1-1][x2]),max(dp[x1-1][y1][x2-1],dp[x1][y1-1][x2-1]));
                   
                   if(pre < 0){
                       continue;
                   }
                   
                   dp[x1][y1][x2] = pre + grid[x1-1][y1-1];
                   if(x1!=x2){
                       dp[x1][y1][x2] += grid[x2-1][y2-1];
                   }
               } 
            }
        }
        
        return dp[n][n][n] < 0 ? 0 : dp[n][n][n];
        
    }
};