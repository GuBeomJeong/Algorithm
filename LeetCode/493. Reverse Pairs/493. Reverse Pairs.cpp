class Solution {
public:
    
    int result = 0;
    vector<int> temp;
    
    void sort(vector<int>& nums,int s,int e){
        
        if(s >= e){
            return;
        }
        
        int m = (s+e)/2;
        
        sort(nums,s,m);
        sort(nums,m+1,e);
        
        merge(nums,s,m,e);
        
    }
    
    int find(vector<int>&nums,int s,int e, int target){
        
        int m;
        
        while(s<e){
            m = (s+e)/2;
            if((long long)nums[m] * (long long)2 < (long long)target){
                e = m;
            }else{
                s = m + 1;
            }
        }
        
        if((long long)nums[s] *2 < target){
            return s;
        }else{
            return s+1;
        }
    }
    
    void merge(vector<int>&nums,int s,int m,int e){
        
        int i = 0;
        int j = m - s + 1;
        int idx = 0;
        
        
        while(i < m - s + 1 && j < e - s + 1){
            while(i < m - s + 1 && nums[s+i] > nums[s+j]){
                result += e - find(nums,m+1,e,nums[s+i]) + 1;
                temp[idx] = nums[s+i];
                idx++;
                i++;
            }
            
            while(j < e - s + 1 && nums[s+i] <= nums[s+j]){
                temp[idx] = nums[s+j];
                idx++;
                j++;
            }
        }
        
        while(i < m - s + 1){
            result += e - find(nums,m+1,e,nums[s+i]) + 1;
            temp[idx] = nums[s + i];
            idx++;
            i++;
        }
        
        while(j < e - s + 1){
            temp[idx] = nums[s + j];
            idx++;
            j++;
        }
        
        for(int k = 0; k < idx; k ++){
            nums[s + k] = temp[k];
        }
    }
    
    
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size());
        sort(nums,0,nums.size()-1);
        return result;
    }
};