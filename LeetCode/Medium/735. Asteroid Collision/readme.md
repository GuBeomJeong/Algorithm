# 풀이
Stack

```c++
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> plus;
        vector<int> result;
        
        for(int asteroid : asteroids){
            if(asteroid > 0){
                plus.push_back(asteroid);
            }
            else if(asteroid < 0){
                if(plus.empty()){
                    result.push_back(asteroid);
                }else{
                    while(!plus.empty() && -asteroid > plus.back()){
                        plus.pop_back();
                    }
                    
                    if(plus.empty()){
                        result.push_back(asteroid);
                    }
                    
                    if(!plus.empty() && plus.back() == -asteroid){
                        plus.pop_back();
                    }
                }
            }
        }
        
        for(int p : plus){
            result.push_back(p);
        }
        
        return result;
    }
};
```