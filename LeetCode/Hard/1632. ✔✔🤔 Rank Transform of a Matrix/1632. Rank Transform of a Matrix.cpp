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
        vector<int> max_line(n+m,0);
        
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
                max_line[root_c] = max(max_line[root_r], max_line[root_c]);
            }
            
            auto max_line2 = max_line;
            
            for(auto value: values){
                int r = value.first;
                int c = value.second;
                
                int root = find(parent, r);
                result[r][c] = max_line[root] + 1;
                max_line2[r] = max_line[root] + 1;
                max_line2[n + c] = max_line[root] + 1;
            }
            
            max_line = max_line2;
        }
        
        return result;
        
    }
};
