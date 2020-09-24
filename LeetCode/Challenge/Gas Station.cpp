class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int idx = 0;
        int num = 0;
        int start = 0;
        
        while(num < (2 * n)){
            sum += gas[idx] - cost[idx];
            
            idx = (idx + 1) % n;
            num++;
            
            if(sum >= 0 && start == idx){
                return idx;
            }
            
            if(sum < 0){
                sum = 0;
                start = idx;
            }
        }
        
        return -1;
    }
};
