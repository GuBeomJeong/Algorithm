class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int value = A[0];
        int result = -1;
        int resultA = 0;
        int resultB = 0;
        for(int i=0;i<n;i++){
            if(!(value == A[i] || value == B[i])){
                break;
            }
            if(value != A[i] && value == B[i]){
                resultA++;
            }
            
            if(value == A[i] && value != B[i]){
                resultB++;
            }
            
            if(i == n-1){
                result = resultA < resultB ? resultA : resultB;
            }
        }
        
        resultA = 0;
        resultB = 0;
        value = B[0];
        for(int i=0;i<n;i++){
            if(!(value == A[i] || value == B[i])){
                break;
            }
            if(value != A[i] && value == B[i]){
                resultA++;
            }
            
            if(value == A[i] && value != B[i]){
                resultB++;
            }
            if(i == n-1){
                if(result != -1){
                    result = min(result,min(resultA,resultB));
                }else{
                    result = resultA < resultB ? resultA : resultB;
                }
                
            }
        }
        
        return result;
        
    }
};