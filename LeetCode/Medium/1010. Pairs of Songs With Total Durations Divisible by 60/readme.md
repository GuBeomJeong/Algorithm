#풀이
60의 나머지 값의 합이 60이면 되고, i < j 이기 때문에 그냥 그 전 값 계속 더해주면 된다. 

``` c++
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int save[60] = {0,};
        int result = 0;
        int value;
        
        for(int t : time){
            value = t % 60;
            result += save[(60-value) % 60];
            save[value]++;
        }
        
        return result;
    }
};
```