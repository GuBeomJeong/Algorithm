class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t mask = 1 << 31;
        int idx = 0;
        
        while(mask){
            result += (n & mask) > 0 ? 1 << idx : 0;
            mask = mask >> 1;
            idx++;
        }
        
        return result;
    }
};