class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dup[200] = {-1,};
        int n = s.size();
        int result = 0;
        int start = 0;
        
        for(int i=0;i<200;i++){
            dup[i] = -1;
        }
        
        for(int i=0;i<n;i++){
            if(dup[s[i]] >= start){
                start = dup[s[i]] + 1;
            }
            
            dup[s[i]] = i;
                        
            if(i - start + 1 > result){
                result = i - start + 1;
            }
            
        }
        
        return result;
    }
};