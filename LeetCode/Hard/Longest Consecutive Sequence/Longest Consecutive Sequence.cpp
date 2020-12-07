class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> map; 
        
        for(int i=0;i<n;i++){
            map[nums[i]] = -1;
        }
        
        int result = 1;
        int idx;
        for(int i=0;i<n;i++){
            idx = nums[i];
            if(map[idx] != -1){
                continue;
            }
            
            while(map.count(idx)){
                idx--;
            }
            idx++;
            int value = 1;
            while(map.count(idx)){
                map[idx] = value++;
                idx++;
            }
            if(value > result){
                result = value;
            }
        }   
        return result - 1;
    }
};