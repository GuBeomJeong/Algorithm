# 풀이
각 점들의 끝까지의 최대 길이와 그 개수 저장하면서 이어간다.    
내가 갈 수 있는 점의 길이가 최대값인 경우, 해당 최대값의 개수를 모두 더해준다.    
그러면 해당 점은 최대값의 길이 + 1, 개수는 그 최대값의 점들에 저장되있던 개수를 모두 더한 값이 된다.    
```c++
class Solution {
public:
    
    vector<int> dp;
    vector<int> count;
    
    int find(vector<int>& nums,int idx){
        
        if(dp[idx]){
            return dp[idx];
        }
        
        int n = nums.size();
        int ret = 0;
        
        if(idx == n){
            return 0;
        }
        
        vector<pair<int,int>> save;
        int cnt = 0;
        
        for(int i = idx + 1; i < n; i ++){
            if(nums[idx] < nums[i]){
                int len = find(nums,i);
                save.push_back({len,i});
                ret = max(ret, len);
            }
        }
        
        for(auto s : save){
            cnt += ret == s.first ? count[s.second] : 0;
        }
        
        if(cnt == 0){
            cnt = 1;
        }
        
        count[idx] = cnt;
        dp[idx] = ret + 1;
        return ret + 1;
    }
    
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,0);
        count.resize(n,0);
    
        
        for(int i=0;i<n;i++){
            find(nums,i);
        }
        
        int max_len = 0;
        for(int d : dp){
            max_len = max(max_len,d);
        }
        
        int result = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == max_len){
                result += count[i];
            }
        }
        
        return result;
        
    }
};
```