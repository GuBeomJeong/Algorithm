# 풀이
두 사람이 동시에 출발한다고 생각하고 풀면 된다.   
두 점의 모든 상태에 대해 저장한다.    
원래 그렇게 하려면, 4차원 배열 [x1][y1][x2][y2] 가 되어야 한다.    
하지만 여기서 x1 + y1 = x2 + y2 일 수 밖에 없기 때문에, x2가 결정되면 y2 또한 무조건 결정 된다.    
그래서 3차원 배열로 사용이 가능하다.   
[x1-1][y1][x2] : A down, B right   
[x1][y1-1][x2] : A right, B right   
[x1-1][y1][x2-1] : A down, B down   
[x1][y1-1][x2-1] : A right, B down    
이전 결과에 대해서 이렇게 총 4가지만 나올 수 있다.    
그래서 이 4가지 경우 중 가장 큰 값이 가능한 전 단계 중 가장 큰 값이 된다.    
```c++
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
```