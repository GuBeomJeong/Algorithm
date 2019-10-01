# First Missing Positivie

가장 처음에 푼 방법이다. 시간복잡도 O(N) 공간복잡도 O(N)이다.
4ms가 걸렸다.
``` c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        bool exist[10000000];
        int len = nums.size();
        
        for(int i=1;i<=len;i++){
            exist[i] = 0;
        }
        
        for(int i=0;i<len;i++){
            if(nums[i] > 0 && nums[i] <= len){
            exist[nums[i]] = 1;
            }
        }
        
        for(int i=1;i<=len;i++){
            if(!exist[i]){
                return i;
            }
        }
        
        return len + 1;
    }
};
```

다음 방법은 시간복잡도 O(N) 공간복잡도 O(1)의 풀이다.
이상하게도 0ms로 나왔다.   
메모리사용량이 왜 똑같은지는 모르겠다.
``` c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int len = nums.size();
        int i = 0;
        
        while(i<len){
            if(nums[i] > 0 && nums[i] <= len 
               && nums[i] != i + 1 && nums[nums[i]-1] != nums[i]){      
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;        
            }else{
                i++;
            }
        }
        
        for(int i=0;i<len;i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        
        return len + 1;
    }
};
```


