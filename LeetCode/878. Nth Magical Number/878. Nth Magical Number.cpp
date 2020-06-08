class Solution {
public:
    
    int gcd(int a,int b){
        
        
        int c;
        
        while(b != 0){
            c = a % b;
            a = b;
            b = c;
        }
        
        return a;
    }
    
    int nthMagicalNumber(int N, int A, int B) {
        
        if(A > B){
            int temp = B;
            B = A;
            A = temp;
        }
        long lcm = A * B / gcd(A,B);
        
        long e = (long)N * A;
        long s = 2;
        long mid = s;
        
        while(s < e){
            mid = (s + e) / 2;
            long cnt = mid / A + mid / B - mid / lcm;
            
            if(cnt < N){
                s = mid + 1;
            }else{
                e = mid;
            }
        }
        return s % ((long)1e9 + 7);
    }
};