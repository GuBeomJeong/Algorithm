class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0){
            return false;
        }
        int m = matrix[0].size();
        if(m == 0){
            return false;
        }
        
        int s = 0;
        int e = n-1;
        int mid;
        
        while(s<=e){
            mid = (s + e) / 2;
            if(matrix[mid][0] <= target && matrix[mid][m-1] >= target ){
                break;
            }
            
            if(matrix[mid][0] > target){
                e = mid - 1;
            }
            
            if(matrix[mid][0] < target){
                s = mid + 1;
            }
        }
        
        if(s > e){
            return false;
        }
        
        for(int i=0;i<m;i++){
            if(matrix[mid][i] == target){
                return true;
            }
        }
        
        return false;
    }
};