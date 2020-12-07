# Buddy Strings
아무생각없이 풀면 틀림   

```c++
class Solution {
public:
    
    void swap(string& str, int i,int j){
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
    
    bool buddyStrings(string A, string B) {

        int n = A.size();
        int count[26] = {0};
        
        if(n != B.size()){
            return false;
        }
        
        int idx = -1;
        
        for(int i =0;i < n ; i ++){
            if(A[i] != B[i]){
                if(idx == -1){
                    idx = i;
                }else{
                    swap(A,i,idx);
                    return A == B;
                }
            }
            count[A[i] - 'a']++;
        }
        
        if(idx == -1){
            for(auto cnt : count){
                if(cnt > 1){
                    return true;
                }
            }
        }
        return false;
    }
};
```