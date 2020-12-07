class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n==0){
            return 0;
        }
        int first_start = timeSeries[0];
        int start = timeSeries[0];
        
        int result = 0;
        
        for(int i = 1; i < n; i++){
            int time = timeSeries[i];
            if(time <= start + duration){
                start = time;
            }else{
                result += start + duration - first_start;
                start = time;
                first_start = time;
            }
        }
        
        result += start + duration - first_start;
        
        return result;
    }
};
