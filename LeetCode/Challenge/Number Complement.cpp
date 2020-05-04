class Solution {
public:
    int findComplement(int num) {
        
        if(num == 0){
            return 1;
        }
        
        int result = 0;
        long long val = 1;
        
        while(num > 0){
            result += val * (((long long)num + 1) % 2);
            num /= 2;
            val *= 2;
        }
        
        return result;
    }
};