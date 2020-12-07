class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int value = 1;
        
        vector<vector<int>> result = vector<vector<int>> (n, vector<int>(n,0));
        
        int grade = 0;
        
        for(int i=n;i>=0;i-=2){
            for(int j=0;j<i;j++){
                result[grade][grade+j] = value++;
            }
            
            for(int j=0;j<i-1;j++){
                result[grade+j + 1][n-grade-1] = value++;
            }
            
            for(int j=0;j<i-1;j++){
                result[n-grade-1][n-grade-j-2] = value++;
            }
            
            for(int j=0;j<i-2;j++){
                result[n-grade-2-j][grade] = value++;
            }
            
            grade++;
        }
        
        return result;
        
    }
};