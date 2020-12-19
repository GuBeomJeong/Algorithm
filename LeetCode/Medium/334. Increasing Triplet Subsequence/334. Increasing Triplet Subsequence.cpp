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