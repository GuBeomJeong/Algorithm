class Solution {
public:
    
    vector<vector<int>> result;
    vector<int> temp;
    int n;
    int t;
    
    void dfs(vector<int>& candi, int idx, int sum){
        sum += candi[idx];
        temp.push_back(candi[idx]);
        
        if(sum == t){
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        
        if(sum > t){
            temp.pop_back();
            return;
        }
        
        
        for(int i = idx; i < n;i++){
            dfs(candi,i,sum);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        t = target;
        
        for(int i=0;i<n;i++){
            dfs(candidates,i,0);    
        }
        
        
        return result;
        
    }
};
