class Solution {
public: 
    int findIntegers(int num) {
        int f[32];
        
        f[0] = 1;
        f[1] = 2;
        
        for(int i=2;i<32;i++){
            f[i] = f[i-1] + f[i-2];
        }
        
        int result = 0;
        bool pre = false;
        for(int i=30;i>=0;i--){
            if(num & (1 << i)){
                result += f[i];
                if(pre) return result;
                pre = true;
            }else{
                pre = false;
            }
        }
        
        return result + 1;
    
    }
};