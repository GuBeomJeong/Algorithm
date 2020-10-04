class Solution {
public:
    
    vector<vector<int>> dp;
    vector<vector<bool>> visit;
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int find(vector<vector<int>>& matrix, int x,int y){
        
        visit[x][y] = true;
        int ret = 0;
        
        if(dp[x][y]){
            visit[x][y] = false;
            return dp[x][y];
        }
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] > matrix[x][y] && !visit[nx][ny]){
                ret = max(ret,find(matrix,nx,ny));
            }
        }
        
        visit[x][y] = false;
        
        return dp[x][y] = ret + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        
        if(n == 0){
            return 0;
        }
        
        m = matrix[0].size();
        
        if(m == 0){
            return 0;
        }
        
        dp.resize(n,vector<int>(m,0));
        visit.resize(n,vector<bool>(m,0));
        
        int result = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result = max(result,find(matrix,i,j));
            }
        }
        
        return result;
    }
};