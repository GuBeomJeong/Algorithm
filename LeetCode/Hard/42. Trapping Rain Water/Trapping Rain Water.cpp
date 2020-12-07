class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> right(n);
        vector<int> left(n);
        
        int max_value = 0;
        for(int i=0;i<n;i++){
            left[i] = max_value;
            if(height[i] > max_value){
                max_value = height[i];
            }
        }
        
        max_value = 0;
        for(int i=n-1;i>=0;i--){
            right[i] = max_value;
            if(height[i] > max_value){
                max_value = height[i];
            }
        }
        
        int result = 0;
        
        for(int i=0;i<n;i++){
            int val = min(right[i],left[i]);
            if(height[i] < val){
                result += val - height[i];
            }
        }
        
        return result;
    }
};
    