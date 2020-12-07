# Maximal Rectangle
height[j] = 현재 행으로부터 위의 행으로의 연속된 1의 크기   
left[j] = j열에서 현재 위로 height[j] 크기 만큼가지고 있는 열들의 행 왼쪽 경계값과 현재 열의 행의 왼쪽 경계값 중 큰 값   
right[j] = left[j] 의 right 버전    

``` c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        
        if(n==0){
            return 0;
        }
        int m = matrix[0].size();
        if(m == 0){
            return 0;
        }
        
        vector<int> left(m,0);
        vector<int> right(m,m-1);
        vector<int> height(m,0);
        
        int left_end, right_end;
        int result = 0;
        
        for(int i=0;i<n;i++){
            left_end = 0;
            right_end = m;
            
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    left[j] = max(left[j],left_end);
                }else{
                    left_end = j+1;
                    left[j] = 0;
                }
            }
            
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j],right_end);
                }else{
                    right_end = j-1;
                    right[j] = m;
                }
            }
            
            for(int j=0;j<m;j++){
                result = max(result,height[j] * (right[j] - left[j]));
            }
        }
        
        return result;
    }
};

```
