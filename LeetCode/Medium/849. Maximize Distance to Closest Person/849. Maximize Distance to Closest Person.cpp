class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int start = -1;
        int result = 0;
        int left = 0;
        
        for(int i=0;i<n;i++){
            if(seats[i]){
                left = i;
                start = i;
                break;
            }
        }
        
        for(int i=left;i<n;i++){
            if(seats[i]){
                result = max(result, i - start);
                start = i;
            }
        }
        
        if(seats[n-1] == 0){
            if(n - 1 - start > result / 2){
                result = 2 * (n-1-start);
            }
        }
        
        if(left > result / 2){
            return left;
        }
        
        return result / 2;
    }
};