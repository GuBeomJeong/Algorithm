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