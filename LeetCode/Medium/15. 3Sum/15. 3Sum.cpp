class Solution {
public:
    
    bool find(vector<int>& nums, int s,int e,int x){
        int m = (s + e) / 2;
        
        if(s<=e){
            if(nums[m] < x){
                return find(nums,m+1,e,x);
            }else if(nums[m] > x){
                return find(nums,s,m-1,x);
            }else{
                return true;
            }
        }
        
        return false;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> result;
        
        sort(nums.begin(),nums.end());
        
        int value = 0;
        bool zero = false;
        for(int i=0;i<n-2;i++){
            if(nums[i] > 0){
                break;
            }
            if(nums[i] == 0){
                if(zero){
                    break;
                }
                zero = true;
            }
            
            for(int j=i+1;j<n-1;j++){
                value = nums[i] + nums[j];
                if(value > 0){
                    break;
                }
                if(find(nums,j+1,n-1,-value)){
                    result.insert({nums[i],nums[j],-value});
                }
            }
        }
        
        return vector<vector<int>> (result.begin(),result.end());
    }
};