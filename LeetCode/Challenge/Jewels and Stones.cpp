class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n = J.size();
        int m = S.size();
        int result = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(J[i] == S[j]){
                    result++;
                }
            }
        }
        return result;
    }
};