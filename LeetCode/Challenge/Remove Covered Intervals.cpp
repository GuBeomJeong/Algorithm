class Solution {
public:
    
    static bool cmp(vector<int>& a,vector<int>& b){
        
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        
        int n = intervals.size();
        
        int result = n;
        
        for(int i=0;i<n;i++){
            if(intervals[i][0] == -1){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(intervals[j][0] != -1 && intervals[i][1] >= intervals[j][1]){
                    intervals[j][0] = -1;
                    result--;
                }
            }
        }
        return result;
    }
};