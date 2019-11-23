# Maximum Equal Frequency
save = 숫자들의 등장 횟수   
value = 등장 횟수의 개수   
이렇게 저장하고 value가 여태 등장했던 숫자보다 1개 적을 경우가 문제의 답이다.   
그 외 1가지 경우는 value가 여태 등장했던 숫자와 같을 경우이다.
```c++
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        
        int n = nums.size();
        int save[100001];
        int value[100001];
        
        for(int i=0;i<100001;i++){
            save[i] = 0;
            value[i] = 0;
        }
        
        int count = 0;
        bool flag = false;
        int answer = 0;
               
        for(int i=0;i<n;i++){
            int num = nums[i];
            
            if(save[num] == 0){
                count++;
            }
            
            save[num]++;
            value[save[num]]++;
            value[save[num] - 1]--;
            
            int cur = value[save[num]];
            int pre = value[save[num] - 1];
            
            if(flag){
                if(cur == 1){
                    answer = i;
                    flag = false;
                }
            }
            
            if(cur == count - 1 || pre == count - 1){
                if(value[1] == 1 || value[save[num] + 1] == 1 ){
                    answer = i;
                }      
            }
            if(cur == count || pre == count){
                if(save[num] == 1){
                    answer = i;
                }
                flag = true;
            }else{
                flag = false;
            }
        }
     
        return answer + 1;
        
    }
};
```
>Success
Details 
Runtime: 80 ms, faster than 87.11% of C++ online submissions for Maximum Equal Frequency.
Memory Usage: 15.2 MB, less than 100.00% of C++ online submissions for Maximum Equal Frequency.
