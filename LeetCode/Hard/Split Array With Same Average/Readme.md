# Split Array With Same Average
<a href="https://leetcode.com/problems/split-array-with-same-average/">Split Array With Same Average</a>   
## First Solution
재미있는 문제이다. 두 개의 서브 배열의 평균값이 같으려면 두 개의 평균이 총 배열의 평균이여야한다는 것은 식 계산으로 알 수 있다. dfs로 가지치기 하면서 
풀었고, Accept가 되었지만 속도가 매우 느렸다. 다른 방법으로 풀어봐야 할 것 같다.

> Runtime: 1012 ms, faster than 8.18% of C++ online submissions for Split Array With Same Average.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Split Array With Same Average.


```C++
class Solution {
public:
    
    int answer[30];
    
    bool find(vector<int>& A){
        int n = A.size();
        
        for(int i=0;i < n ; i++){
            if(find(A,i,0,0)){
                return true;
            }
        }
        return false;
    }
    
    
    bool find(vector<int>& A,int idx,int sum,int cnt){
        
        int n = A.size();
        
        cnt++;
        
        sum += A[idx];
        
        if(sum > answer[cnt]){
            return false;
        }
    
        if(sum == answer[cnt]){
            return true;
        }
        
        if(cnt == n/2){
            return false;   
        }
        
        for(int i = idx + 1; i < n ; i ++){
            if(A[i] == 10001){
                continue;
            }
            if(find(A,i,sum,cnt)){
                return true;
            }
        }
        
        return false;
    }
    
    
    bool splitArraySameAverage(vector<int>& A) {
        
        int n = A.size();
        sort(A.begin(),A.end());
        
        if(n == 1){
            return false;
        }
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += A[i];
        }
        
        int dup = 0;
        
        for(int i = 1; i < n ; i ++){
            if(A[i] == A[i-1]){
                dup++;
                A[i] = 10001;
            }
        }
        
        for(int i = 1 ; i <= n/2;i++){
            if(sum * i % n == 0){
                answer[i] = sum * i / n;
            }else{
                answer[i] = INT_MAX;
            }
        }
        
        return find(A);
    }
};
```
