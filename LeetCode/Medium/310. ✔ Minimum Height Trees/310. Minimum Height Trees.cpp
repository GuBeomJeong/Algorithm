class Solution {
public:
    
    vector<vector<int>> nodes;
    vector<bool> visit;
    int max_len = 0;
    int max_idx;
    vector<int> route;
    
    void find(int idx, int depth){
        
        visit[idx] = true;
        
        if(depth > max_len){
            max_len = depth;
            max_idx = idx;
        }
        
        for(int node : nodes[idx]){
            if(!visit[node]){
                find(node,depth+1);
            }
        }
    }
    
    bool find_route(int idx, int end){
        visit[idx] = true;
        
        if(idx == end){
            route.push_back(idx);
            return true;
        }
        
        for(int node : nodes[idx]){
            if(!visit[node]){
                if(find_route(node,end)){
                    route.push_back(idx);
                    return true;
                }
            }
        }
        return false;
    }
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        nodes.resize(n+1);
        visit.resize(n+1,false);
        
        if(n == 1){
            return vector<int>(1,0);
        }
        
        if(n==2){
            vector<int> result;
            result.push_back(0);
            result.push_back(1);
            return result;
        }
        
        for(auto edge: edges){
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        
        find(0,0);
        
        visit.clear();
        visit.resize(n+1,false);
        max_len = 0;
        int start_idx = max_idx;
        
        find(max_idx,0);
        int end_idx = max_idx;
        
        visit.clear();
        visit.resize(n+1,false);
        find_route(start_idx,end_idx);
                
        vector<int> result;
        
        int rn = route.size();
        if(rn % 2 == 0){
            result.push_back(route[rn/2-1]);
            result.push_back(route[rn/2]);
        }else{
            result.push_back(route[rn/2]);
        }
        
        return result;
    }
};