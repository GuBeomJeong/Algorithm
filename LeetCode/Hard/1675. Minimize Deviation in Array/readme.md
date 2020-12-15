# 풀이
모든 홀수에 2를 곱해서 짝수를 만들어 놓으면, 나눗셈 연산만으로도 답을 구할 수 있게 된다.   
가장 큰 값과 가장 작은 값을 항상 알고 있어야 하는데, 나눗셈 연산만 할 것이기 때문에 가장 큰 값을 계속 나눠주는 방식으로 해야한다.    
그래서 이 경우 heap 이 가장 좋은 경우가 된다.   
가장 큰 값이 홀수이면 결국 더 작은 차이를 낼 수 없으므로 (더 작은 값이 홀수가 없으므로) 홀수이면 멈추면 된다.   
```c++
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        int min_num = INT_MAX;
        int ret = INT_MAX;
        
        for(int num : nums){
            if(num % 2 == 1){
                num *= 2;
            }
            min_num = min(min_num, num);
            pq.push(num);
        }
        
        while(pq.top() % 2 == 0){
            int max_num = pq.top();
            ret = min(ret, max_num - min_num);
            min_num = min(min_num, max_num / 2);
            pq.push(max_num / 2);
            pq.pop();
        }
        
        ret = min(ret, pq.top() - min_num);
        
        return ret;
    }
};
```