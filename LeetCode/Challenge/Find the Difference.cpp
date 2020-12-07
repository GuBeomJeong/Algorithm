class Solution {
public:
    char findTheDifference(string s, string t) {
        int alpha[26];
        
        for(int i=0;i<26;i++){
            alpha[i] = 0;
        }
        
        for(auto c : t){
            alpha[c-'a']++;
        }
        
        for(auto c : s){
            alpha[c-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(alpha[i] > 0){
                return i + 'a';
            }
        }
        
        return ' ';
    }
};
