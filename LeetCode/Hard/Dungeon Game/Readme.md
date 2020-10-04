# Dungeon Game

## first solution.
처음 생각했던 방법, 한번 돌면서 가장 체력이 많이 필요한경우를 알아낸 후 가장 많은 체력이 필요한 경우부터 이분법으로 dfs로 가능한지 여부 확인.
시간초과 났다.
```c++
class Solution {
public:
    
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    int n,m;
    
    bool dfs(vector<vector<int>>& dungeon,int hp,int x,int y){
        
        if( x == n - 1 && y == m - 1){
            return true;
        }
        
        for(int i=0;i<2;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < n && ny < m && hp + dungeon[nx][ny] > 0){
                if(dfs(dungeon,hp + dungeon[nx][ny],nx,ny)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       
        n = dungeon.size();
        m = dungeon[0].size();
        
        vector<vector<int>> need(n);
        
        for(int i = 0 ; i <n ; i++){
            need[i].resize(m,0);
        }
        
        
        need[0][0] = dungeon[0][0];
        int hp = need[0][0];
        
        if(n == 1 && m == 1){
            if(hp > 0){
                return 1;
            }
            return -hp + 1;
        }
        
        for(int i=1;i<m;i++){
            
            need[0][i] = dungeon[0][i] + need[0][i-1];
            
            if(hp > need[0][i]){
                hp = need[0][i];
            }
        }
        
        for(int i=1;i<n;i++){
            
            need[i][0] = dungeon[i][0] + need[i - 1][0];
            
            if(hp > need[i][0]){
                hp = need[i][0];
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                need[i][j] = dungeon[i][j] + max(need[i-1][j],need[i][j-1]);
                if(hp > need[i][j]){
                    hp = need[i][j];
                }
            }
        }
        
        if(hp >= 0){
            return 1;
        }else{
            hp = -hp;
        }
        
        int low = 1;
        int high = hp + 2;
        int mid;
        
        
        
        while(low < high){
            
            mid = (low + high) / 2;
            
            if(mid + dungeon[0][0] > 0 && dfs(dungeon,mid + dungeon[0][0],0,0)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};
```

## Second Solution.
맨 마지막부터 필요한 체력을 갱신하면서 올라간다. 현재 필요한 체력 hp에 이 전 dungeon 값을 뺀 값이 다음에 필요한 체력이 될 것이고
현재 필요한 체력보다 더 큰 값이 들어올 경우는 그 때의 던전 값이 체력을 다 채워줄 수 있는 것이므로 1만 필요하다.

```c++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> hp(n);
        for(int i=0;i<n;i++){
            hp[i].resize(m,INT_MAX-1);
        }
        
        hp[n-1][m-1] = dungeon[n-1][m-1] < 0 ? -dungeon[n-1][m-1] + 1 : 1;
        
        for(int i=n-1;i>=0;i--){
            for(int j = m-1; j >= 0 ; j--){
                if(i > 0){
                    hp[i-1][j] = min(hp[i-1][j], max(1, hp[i][j] - dungeon[i-1][j]));
                }
                
                if(j>0){
                    hp[i][j-1] = min(hp[i][j-1], max(1,hp[i][j]-dungeon[i][j-1]));
               } 
            }
        }
        
        return hp[0][0];
        
    }
};
```

> Runtime: 8 ms, faster than 69.02% of C++ online submissions for Dungeon Game.
Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Dungeon Game.

