class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int M = 1000000007;
        vector<long long> dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0:1;
        
        for(int i=1;i<n;i++){
            if(s[i] == '*'){
                dp[i+1] = dp[i] * 9;
                if(s[i-1] == '1'){
                    dp[i+1] = (dp[i+1] + 9 * dp[i-1]) % M;
                }else if(s[i-1] == '2'){
                    dp[i+1] = (dp[i+1] + 6 * dp[i-1]) % M;
                }else if(s[i-1] == '*'){
                    dp[i+1] = (dp[i+1] + 15 * dp[i-1]) % M;
                }
            }else{
                dp[i+1] = s[i] == '0' ? 0 : dp[i];
                
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                    dp[i+1] = (dp[i+1] + dp[i-1]) % M;
                }else if(s[i-1] == '*'){
                    dp[i+1] = (dp[i+1] + (s[i] <= '6' ? 2:1) * dp[i-1]) % M;
                }
            }
        }
        return dp[n];
    }
};