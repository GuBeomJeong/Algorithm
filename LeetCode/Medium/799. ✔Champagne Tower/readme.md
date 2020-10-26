# 풀이
관점이 정말 중요하다.   
맨 윗잔에 다 붇고 계속 아래로 반씩 떨어지는 것으로 생각하면 편하다.    
시간 이런 것 신경 쓰다 아예 다른 길로 간다.    
```c++
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double cup[query_row+2][query_row+2];
        
        for(int i=0;i<=query_row+1;i++){
            for(int j=0;j<=i;j++){
                cup[i][j] = 0;
            }
        }
        
        cup[0][0] = poured;
        
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                if(cup[i][j] >=1){
                    cup[i+1][j] += (cup[i][j] - 1) / 2.0;
                    cup[i+1][j+1] += (cup[i][j] - 1) / 2.0;
                    cup[i][j] = 1;
                }
                
            }
        }
        
        return cup[query_row][query_glass];
    }
};
```