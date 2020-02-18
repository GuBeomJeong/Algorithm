class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int begin = -2;
        int end = -1;
        
        
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                if(begin == -2){
                    begin = i - 1;
                }
                end = max(i + 2,end);
                while(begin >= 0 && nums[i + 1] < nums[begin]){
                    begin--;
                }
                while(end < n  && nums[i] > nums[end]){
                    end++;
                }
            }
        }
        
        if(end == -1){
            return 0;
        }
        
        return end - begin - 1;
    }
};