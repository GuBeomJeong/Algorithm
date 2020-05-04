// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long s = 0;
        long long e = n;
        long long m;
        
        while(s < e){
            m = (s+e)/2;
            if(isBadVersion(m)){
                e = m;
            }else{
                s = m+1;
            }
        }
        
        return s;
    }
};