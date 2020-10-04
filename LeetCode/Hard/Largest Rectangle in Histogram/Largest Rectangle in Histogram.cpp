class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        int n = heights.size();
        
        if(n == 0){
            return 0;
        }
        
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = -1;
        right[n-1] = n;
        
        
        for(int i=1;i<n;i++){
            int l = i - 1;
            
            while(l >=0 && heights[l] >= heights[i]){
                l = left[l];
            }
            
            left[i] = l;
        }
        
        for(int i=n-2;i>=0;i--){
            int r = i + 1;
            
            while(r < n && heights[r] >= heights[i]){
                r = right[r];
            }
            
            right[i] = r;
        }
        
        int ret = 0;
        
        for(int i=0;i<n;i++){
            ret = max(ret, heights[i] * (right[i] - left[i] - 1) );
        }
        
        return ret;
    }
};