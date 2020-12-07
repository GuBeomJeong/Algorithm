class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return vector<string>();
        }
        if(n == 1){
            return vector<string>(1,to_string(nums[0]));
        }
        int start = 0;
        vector<string> result;
        
        for(int i=1; i < n;i++){
            if(nums[i] != nums[i-1] + 1){
                if(i-1 == start){
                    result.push_back(to_string(nums[i-1]));
                }else{
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }
                start = i;
            }
        }
        
        if(nums[n-1] == nums[n-2] + 1){
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[n-1]));
        }else{
            result.push_back(to_string(nums[n-1]));
        }
        
        return result;
    }
};