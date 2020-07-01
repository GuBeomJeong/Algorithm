class Solution {
public:
    int arrangeCoins(int n) {
        int k = 1;
        while(n){
            if(n < k){
                return k-1;
            }
            n -= k++;
        }
        return k-1;
        
    }
};