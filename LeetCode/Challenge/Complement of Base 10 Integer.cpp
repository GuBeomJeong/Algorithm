class Solution {
public:
    int bitwiseComplement(int N) {
        int result = 0;
        int binary = 1;
        
        if( N == 0){
            return 1;
        }
        
        while(N != 0){
            result += ((N+1) % 2) * binary;
            N /= 2;
            binary *= 2;
        }
        
        return result;
    }
};