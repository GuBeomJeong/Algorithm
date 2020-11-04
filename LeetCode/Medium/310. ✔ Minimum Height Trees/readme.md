# 풀이
트리에서 가장 거리가 먼 두 노드를 찾는다. (트리의 지름)    
<b>트리의 지름</b>   
x 에서 가장 먼 y를 찾는다.   
y 에서 가장 먼 z를 찾는다.   
y ~ z 가 해당 트리에서 가장 먼 두 점이 된다.    
그렇게 가장 먼 두 노드를 찾으면, 그 두 점의 경로의 중간 값이 가장 높이가 낮은 트리의 루트가 된다.   
왜냐하면 두 중간 값을 제외한 다른 점들이 루트가 되면, 그 가장 길이가 긴 두 점 사이의 거리의 절반 보다 항상 큰 값이 나오기 때문이다.   
``` c++
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
```
