class Solution {
public:
    
    vector<vector<int>> map;
    vector<bool> visit;
    int limit;
    int final_depth = 0;
    
    int dfs(int idx, int depth){
        int ret = 0;
        
        visit[idx] = true;
        
        if(idx == 1){
            final_depth = depth;
            return map[idx].size();
        }
        
        if(depth == limit){
            return 0;
        }
        
        for(auto vertex : map[idx]){
            if(!visit[vertex]){
                ret = dfs(vertex,depth+1);
                if(ret){
                    if(depth == 0){
                        return ret;
                    }
                    return ret * (map[idx].size() - 1);
                }
            }
        }
        
        visit[idx] = false;
        
        return 0;
    }
    
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        if(n == 1 && target==1){
            return 1;
        }
        
        map.resize(n+1);
        visit.resize(n+1,false);
        limit = t;
        
        for(auto edge: edges){
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        
        if(target == 1 && t >= 1 && map[1].size() > 0){
            return 0;
        } 
        
        int result = dfs(target,0);
        
        if(result == 0){
            return 0;
        }
        
        if(map[target].size() > 1){
            if(final_depth < t){
                return 0;
            }
        }
        
        return (double)1 / (double) result;
    }
};
