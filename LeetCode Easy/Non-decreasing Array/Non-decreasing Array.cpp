class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size();
        bool check = false;
        
        
        for(int i=0;i< n -1;i++){
            if(nums[i] > nums[i + 1]){
                if(check){
                    return false;
                }else{
                    if(i > 0 && i < n - 1){
                        if(nums[i - 1] <= nums[i+1]){
                            check = true;
                        } 
                    }else{
                        check = true;
                    }
                    
                    if(i < n - 2){
                        if(nums[i] <= nums[i+2]){
                            check = true;
                        }
                    }else{
                       check = true; 
                    }
                    
                    
                    if(!check){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};