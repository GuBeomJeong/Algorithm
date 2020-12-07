class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n,0);
        vector<vector<bool>> p(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            cut[i] = i;
            
            for(int j=0;j<=i;j++){
                if(s[i] == s[j] && ( j + 1 > i -1 || p[j+1][i-1] )){
                    p[j][i] = true;
                    cut[i] = j == 0 ? 0 : min(cut[i], cut[j-1] + 1 );
                }
            }
        }
        
        return cut[n-1];
    }
};