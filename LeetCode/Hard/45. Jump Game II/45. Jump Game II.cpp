class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1){
            return 0;
        } 
        
        vector<int> save(n,n);
        
        for(int i= n-2;i >=0 ;i--){
            if(n - 1 - i <= nums[i]){
                save[i] = 1;
                continue;
            }
            
            for(int j = i+1 ; j <= i + nums[i];){
                if(j > n - 2){
                    break;
                }
                
                if( i + nums[i] >= j + nums[j]){
                    save[i] = min(save[i],save[j] - 1);
                    j += nums[j] + 1;
                }else{
                    save[i] = min(save[i],save[j]);
                    j++;
                }
            }    
            save[i]++;
             
        }
        
        return save[0];
    }
};