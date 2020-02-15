class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 0){
            return vector<int>();
        }
        
        list<int> save;
        vector<int> result(n - k + 1,0);
        int ridx = 0;
        
        for(int i=0;i<n;i++){
            
            while(!save.empty() && save.front() == i - k){
                save.pop_front();
            }
            
            while(!save.empty() && nums[save.back()] < nums[i]){
                save.pop_back();
            }
            
            save.push_back(i);
            
            if(i >= k-1){
                result[ridx++] = nums[save.front()];
            }
        }
        
        return result;
        
    }
};