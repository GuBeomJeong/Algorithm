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