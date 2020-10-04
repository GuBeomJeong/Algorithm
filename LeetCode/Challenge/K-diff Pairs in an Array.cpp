class Solution {
public:
    int findPairs(vector<int>& nums, int k) {       
        int n = nums.size();
        int result = 0;
        
        sort(nums.begin(),nums.end());
        if(k == 0){
            bool check = false;
            for(int i =1;i<n;i++){
                if(nums[i] == nums[i-1]){
                    if(!check){
                        result++;
                    }
                    check= true;
                }else{
                    check = false;
                }
            }
            return result;
        }
        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        
        n = nums.size();
        
        int i = 0;
        int j = 1;
        
        while(j < n){
            if(nums[j] - nums[i] == k){
                result++;
                j++;
                i++;
            }
            
            while(j < n && nums[j] - nums[i] < k){
                j++;
            }
            
            while(j < n && nums[j] - nums[i] > k){
                i++;
                if(i == j){
                    j++;
                }
            }
            
            
        }
        
        return result;
    }
};
