class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int value = -nums[i];
            int start = i + 1;
            int end = n-1;
            
            while(start < end){
                int sum = nums[start] + nums[end];
                
                if(sum > value){
                    end--;
                }else if(sum < value){
                    start++;
                }else{
                    result.push_back({-value,nums[start],nums[end]});
                    
                    int s_val = nums[start++];
                    int e_val = nums[end--];
                    
                    while(start < end && nums[start] == s_val){
                        start++;
                    }
                    
                    while(start < end && nums[end] == e_val){
                        end--;
                    }
                }
            }
            
        }
        
        return result;
    }
};