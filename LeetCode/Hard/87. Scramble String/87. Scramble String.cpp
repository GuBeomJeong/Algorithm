class Solution {
public:
    
    unordered_map<string,unordered_map<string,bool>> check;
    
    bool divide(string s1, string s2){
        int n = s1.size();
        
        int count[26] = {0};
        for(int i =0;i < n;i++){
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        
        for(int cnt:count){
            if(cnt != 0){
                return false;
            }
        }
        
        if(check.find(s1) != check.end() && check[s1].find(s2) != check[s1].end()){
            return check[s1][s2];
        }
        
        if(s1 == s2){
            check[s1][s2] = true;
            return true;
        }
        
        for(int i = 1 ; i < n ; i++){
            string left = s1.substr(0,i);
            string right = s1.substr(i, n - i);
            string left2 = s2.substr(0,i);
            string right2 = s2.substr(i,n-i);
            
            if(divide(left,left2)){
                if(divide(right,right2)){
                    check[s1][s2] = true;
                    return true;
                }
            }
            
            left2 = s2.substr(0,n-i);
            right2 = s2.substr(n-i,i);
            
            if(divide(right,left2)){
                if(divide(left,right2)){
                    check[s1][s2] = true;
                    return true;
                }
            }
        }
        
        check[s1][s2] = false;
        return false;
    }
    
    
    bool isScramble(string s1, string s2) {
        return divide(s1,s2);
    }
};