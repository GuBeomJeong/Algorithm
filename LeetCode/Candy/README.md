# Candy

왼쪽에서 오른쪽으로 연속 증가하는 횟수 , 오른쪽에서 왼쪽으로 연속으로 증가하는 횟수 중 큰 값 + 1이 해당 자리에 채울 수 있는 최소 값이 된다.

``` c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        
        vector<int> up(n,0);
        vector<int> reverse(n,0);
        
        up[0] = 0;
        reverse[n-1] = 0;
        
        for(int i =1; i< n ; i++){
            if(ratings[i] > ratings[i-1]){
                up[i] = up[i-1] + 1;
            }else{
                up[i] = 0;
            }
        }
        
        for(int i = n-2; i>= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                reverse[i] = reverse[i+1] + 1;
            }else{
                reverse[i] = 0;
            }
        }
        
        int result = 0;
        for(int i=0;i<n;i++){
            result += max(up[i],reverse[i]) + 1;
        }
         
        return result;
    }
};
```
> Runtime: 28 ms, faster than 69.85% of C++ online submissions for Candy.
Memory Usage: 11 MB, less than 7.69% of C++ online submissions for Candy.
Next challenges:
