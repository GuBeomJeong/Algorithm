class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> line(5,vector<int>(5));
        line[1][2] = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        line[1][3] = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        line[1][4] = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
        line[2][3] = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
        line[2][4] = (p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]);
        line[3][4] = (p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]);
        
        for(int i=1;i<=4;i++){
            for(int j=i+1;j<=4;j++){
                line[j][i] = line[i][j];
            }
        }
       
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                if(j == i){
                    continue;
                }
                for(int k=1;k<=4;k++){
                    if(k == i || k == j || line[i][j] == 0){
                        continue;
                    }
                    
                    if(line[i][j] == line[i][k] && line[i][j] + line[i][k] == line[j][k]){
                        int rest = 1;
                        for(rest=1;rest<=4;rest++){
                            if(rest != i && rest != j && rest != k){
                                break;
                            }
                        }
                        if(line[rest][j] == line[rest][k] && line[rest][j] + line[rest][k] == line[j][k]){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};