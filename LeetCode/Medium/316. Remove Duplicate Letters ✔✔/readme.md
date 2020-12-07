# 316. Remove Duplicate Letters
상당히 어려워서 답보고 푼 문제    
스택을 사용하여 푼다.   
그리디라고 볼 수 있을 것 같다.   
스택의 top(가장 최근에 추가된 값)부터 자기보다 크고, 그 알파벳의 마지막 인덱스가 현재 인덱스보다 클 때 (즉, 해당 알파벳이 아직 뒤에 남아 있을 때) 그 값은 제대로 추가된 값이 아니다. 그러므로 삭제한다.   
생각해야할 점은 xyzday 라는 문장이 있다고 했을 때, 여기서 y는 뒤에 y가 있다 하지만 d의 차례가 왔을 때 y를 삭제할 수 없다. z가 마지막 인덱스 이기 때문이다.

``` c++
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
```