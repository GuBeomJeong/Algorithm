class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        map<int,int> dic;
        int goal = n / 2;
        for(int i=0;i<n;i++){
            if(dic.count(nums[i])){
                dic[nums[i]]++;
            }else{
                dic[nums[i]] = 1;
            }
            
            if(dic[nums[i]] > goal){
                return nums[i];
            }
        }
        return -1;
    }
};