# 풀이
매트릭스 상에서 가장 작은 값부터 차례대로 구한다.    
중복된 값이 없다면, 해당 row, column 라인의 max 값 중 큰 값 더하기 1 이 무조건 답이 된다.    
( 특정 row, column 에서 가장 큰 값을 항상 갱신한다 - 초기 값은 0 )
     
하지만 중복된 값이 있다면, 다른 중복된 값의 가장 큰 rank 값을 갱신해주어야 한다.    
( 다른 row, col에 있다고 하더라도 row, col 을 따라가다가 겹치는 row나 col이 있다면 그 값을 갱신해 주어야 한다)   
하지만 겹치는 row, col의 값들을 모두 파악하기는 쉽지 않다.    
   
그렇기 때문에 disjoint set을 사용하여 row와 col이 한번이라도 겹치는 순간 같은 그룹에 넣는다.    
같은 그룹에 넣을 때마다 root의 rank 값을 가장 큰 값으로 갱신한다.     
그리고 그 그룹에 모든 점들에 대해 root의 rank값 으로 갱신한다.    

- 어려웠던 점   
이차원 row, col 라인을 disjoint set을 해야했던 것    
- 해결 방법
row 와 col을 같은 1차원으로 만들고 djsjoin set을 하면 편리하다.       
이차원 row 라인과 col 라인을 같은 배열에 넣는 것이 생각하기 쉽지 않았다.      
```c++
class Solution {
public:
    int find(vector<int>& p, int a){
        if(p[a] == a){
            return a;
        }
        return p[a] = find(p,p[a]);
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        map<int, vector<pair<int,int>>> position;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                position[matrix[i][j]].push_back({i,j});
            }
        }
        
        vector<vector<int>> result = vector<vector<int>> (n, vector<int>(m,0));
        vector<int> parent(n+m);
        vector<int> rank(n+m,0);
        
        for(auto pos : position){
            vector<pair<int,int>> values = pos.second;
            
            for(int i=0;i<n+m;i++){
                parent[i] = i;
            }
            
            for(auto value : values){
                int r = value.first;
                int c = value.second;
                
                int root_r = find(parent, r);
                int root_c = find(parent, n + c);
                
                parent[root_r] = root_c;
                rank[root_c] = max(rank[root_r], rank[root_c]);
            }
            
            auto rank2 = rank;
            
            for(auto value: values){
                int r = value.first;
                int c = value.second;
                
                int root = find(parent, r);
                result[r][c] = rank[root] + 1;
                rank2[r] = rank[root] + 1;
                rank2[n + c] = rank[root] + 1;
            }
            
            rank = rank2;
        }
        
        return result;
        
    }
};

```
