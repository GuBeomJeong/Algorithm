# Scramble String
거의 완탐   
모든 경우 다 확인하고 이미 안되는 조합에 대해서는 따로 저장     
느리다   
++ 알파벳 개수 확인 후 시간 향상
``` c++
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
```
>Runtime: 308 ms, faster than 14.43% of C++ online submissions for Scramble String.
Memory Usage: 28.9 MB, less than 5.23% of C++ online submissions for Scramble String.

> 알파벳 개수 확인 후   
> Runtime: 4 ms, faster than 96.57% of C++ online submissions for Scramble String.
Memory Usage: 14.1 MB, less than 5.23% of C++ online submissions for Scramble String.