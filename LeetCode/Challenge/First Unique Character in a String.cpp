class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int exist[26];
        
        for(int i=0;i<26;i++){
            exist[i] = 0;
        }
        
        for(int i=0;i < n; i++){
            exist[s[i] - 'a']++;
        }
        
        for(int i=0;i<n;i++){
            if(exist[s[i] - 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};