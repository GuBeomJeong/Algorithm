class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        bool check[26] = {};
        int last[26] = {};
        string result = "";
        
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
    
        for(int i=0;i<n;i++){
            if(check[s[i] - 'a']) continue;
            check[s[i]-'a'] = true;
            
            while(!result.empty() && result.back() > s[i] && last[result.back()-'a'] > i){
                check[result.back()-'a'] = false;
                result.pop_back();
            }
            
            result.push_back(s[i]);
        }
    
        return result;
    }
};