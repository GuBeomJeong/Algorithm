class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int s = 0;
        int e = n-1;
        int m;
        
        while(s <= e){
            m = (s+e)/2;
            
            if(m < n - 1 && nums[m] == nums[m+1]){
                if(m%2){
                    e = m;
                }else{
                    s = m + 1;
                }
            }else if(m > 0 && nums[m] == nums[m-1]){
                if(m%2){
                    s = m + 1;
                }else{
                    e = m;
                }
            }else{
                return nums[m];
            }
            
        }
        
        return -1;
        
    }
};