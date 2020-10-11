# Minimum Number of Arrows to Burst Balloons
Greedy 하게 풀면 된다.   
end 값을 기준으로 정렬하고 start 가 그 전까지 겹친 end 값 중 가장 작은 값보다 크면 새로운 풍선을 터뜨린다.      
왜냐하면 일단 무조건 모든 풍선에 대해 터뜨려야 하기 때문에 이전 까지 겹쳤던 풍선들과 겹칠 수 없는 풍선이 나오면 그냥 새롭게 터뜨려야 한다.   
```c++
class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0){
            return 0;
        }
        int result = 1;
        
        sort(points.begin(),points.end(),cmp);    
        
        int end = points[0][1];
        
        for(auto point : points){
            if(point[0] > end){
                result++;
                end = point[1];
            }
        }
        
        
        
        return result;
    }
};
```