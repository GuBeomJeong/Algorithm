class Solution {
public:
    int n;
    int m;

    vector<vector<int>> alpha;
    vector<vector<int>> dp;
    
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int m = votes[0].size();
        
        alpha.resize(26, vector<int>(m,0));
        dp.resize(26,vector<int>(26,-1));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                alpha[votes[i][j] - 'A'][j]++;
            }
        }
        
        string result = votes[0];
        
        sort(result.begin(),result.end(),[&](char a,char b)-> bool{
            
            int f = a - 'A';
            int s = b - 'A';
            
            if(dp[f][s] != -1){
                return dp[f][s] == f;
            }
           
            for(int i=0;i<m;i++){
                if(alpha[f][i] > alpha[s][i]){
                    dp[f][s] = f;
                    dp[s][f] = f;
                    return true;
                }else if(alpha[f][i] < alpha[s][i]){
                    dp[f][s] = s;
                    dp[s][f] = s;
                    return false;
                }
            }
            
            dp[f][s] = f < s ? f : s;
            dp[s][f] = dp[f][s];
            
            return a < b;
        });
        
        return result;
    }
};