class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n == 0){
            return vector<int>();
        }
        
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        for(int i=0;i<n;i++){
            if(i % k == 0){
                leftMax[i] = nums[i];
            }else{
                leftMax[i] = max(leftMax[i-1],nums[i]);
            }
        }
        
        rightMax[n-1] = nums[n-1];
        for(int i = n - 2; i >=0;i --){
            if((i + 1) % k == 0){
                rightMax[i] = nums[i];
            }else{
                rightMax[i] = max(rightMax[i+1],nums[i]);
            }
        }
        
        vector<int> result;
        
        for(int i=0;i<n-k+1;i++){
            result.push_back(max(rightMax[i],leftMax[i + k - 1]));
        }
        
        return result;
    }
};