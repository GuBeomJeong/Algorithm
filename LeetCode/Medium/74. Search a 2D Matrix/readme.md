# 풀이
그냥 탐색 문제    
최대 100x100 이라 탐색했어도 괜찮았을 듯

```c++
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
```
>Runtime: 4 ms, faster than 97.80% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.7 MB, less than 16.26% of C++ online submissions for Search a 2D Matrix.