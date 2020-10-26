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