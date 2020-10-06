class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size();
        int one_count = 0;
        
        for(int a : A){
            one_count += a;
        }
                
        if(one_count % 3){
            return {-1,-1};
        }
        
        if(one_count == 0){
            return {0, n-1};
        }
        
        int num = one_count / 3;
        int cnt = 0;
        
        int i = -1;
        int j = -1;
        for(int k = 0; k < n ; k++){
            cnt += A[k];
            if(cnt == num){
                if(i == -1){
                    i = k;
                }else if(j == -1){
                    j = k+1;
                    break;
                }
                cnt = 0;
            }
        }
        
        int first = 0;
        int second = 0;
        int third = 0;
        
        for(int k = 0; k <= i;k++){
            if(A[k]){
                first = k;
                break;
            }
        }
        for(int k = i+1;k<=j;k++){
            if(A[k]){
                second = k;
                break;
            }
        }
        for(int k = j;k<n;k++){
            if(A[k]){
                third = k;
                break;
            }
        }
        
        while(third < n){
            if(A[first] == A[second] && A[second] == A[third]){
                first++;
                second++;
                third++;
            }else{
                return {-1,-1};
            }
        }
        
        return {first-1,second};
        
    }
};