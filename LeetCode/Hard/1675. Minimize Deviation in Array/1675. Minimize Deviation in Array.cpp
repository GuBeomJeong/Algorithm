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