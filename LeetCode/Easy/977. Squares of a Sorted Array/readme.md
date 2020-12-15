# 풀이
O(NlogN)
```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int& num: nums){
            num *= num;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
```
O(N)
```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int r = nums.size() - 1;
        int l = 0;
        
        vector<int> result(nums.size(),0);
        int idx = r;
        
        while(l <= r){
            if(nums[l] * nums[l] > nums[r] * nums[r]){
                result[idx] = nums[l] * nums[l];
                l++;
            }else{
                result[idx] = nums[r] * nums[r];
                r--;
            }
            idx--;
        }
        return result;
    }
};
```