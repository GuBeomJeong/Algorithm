# 풀이
첫 번째로 작은 수 , 두 번째로 작은 수 2개만 유지하면 된다.   
첫번째가 갱신되어도 두 번째는 이 전 값이 유지된다.    

```c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min_first = INT_MAX;
        int min_second = INT_MAX;
        
        for(int num : nums){
            if(num > min_second){
                return true;
            }
            
            if(num <= min_first){
                min_first = num;
                continue;
            }
            
            if(num < min_second){
                min_second = num;
            }
        }
        
        return false;
        
    }
};
```