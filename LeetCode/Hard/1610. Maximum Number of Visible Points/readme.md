# 1610. Maximum Number of Visible Points
처음 보는 유형의 문제   
tangent(angle) = y/x 이기 때문에 angle을 구하기 위해서는 tangent의 역함수 arctangent가 필요하다   
즉, arctangent(y/x) = angle 이다.   
그렇게 모든 점과 현재 자신의 위치의 angle을 다 구한 후 sort 한다.   
두 변수를 사용하여 각의 차이가 주어진 각보다 작은 경우 높은 각을 올려주며 차이를 갱신한다.   
- 한바퀴 돌아오는 각을 재기 위해서 주어진 각보다 작은 각들을 뒤에 추가한다.   
```c++
#define PI 3.14159265
#define MARGIN 1e-9

class Solution {
public:
    
    double getAngle(int x,int y){
        return atan2(y,x) * 180 / PI;
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size();
        vector<double> angles;
        int x = location[0];
        int y = location[1];
        
        int same = 0;
        
        for(auto point : points){
            int x_diff = point[0] - x;
            int y_diff = point[1] - y;
            
            if(x_diff == 0 && y_diff == 0){
                same++;
                continue;
            }
            
            double current_angle = getAngle(x_diff,y_diff);
            
            if(current_angle < 0){
                current_angle += 360;
            }
            angles.push_back(current_angle);
        }
        
        sort(angles.begin(),angles.end());
        vector<double> circle_angles = angles;
        for(auto a:angles){
            if(a >angle) break;
            circle_angles.push_back(a);
        }
        // circle_angles.insert(circle_angles.end(),angles.begin(),angles.end());
        n = circle_angles.size();
        for(int i = angles.size(); i < n; i++){
            circle_angles[i] += 360;
        }
        
        int j = 0;
        int ret = 0;
        for(int i = 0; i < n ; i ++){
            while(j < n && circle_angles[j] - circle_angles[i] <= angle + MARGIN){
                j++;
            }
            
            ret = max(ret, j - i);
        }
        
        return ret + same;
        
    }
};
````