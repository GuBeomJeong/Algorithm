class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> map(1001,0);
        int sum = 0;
        
        for(auto trip : trips){
            map[trip[1]] += trip[0];
            map[trip[2]] -= trip[0];
        }
        
        for(int i=0;i<1001;i++){
            sum += map[i];
            if(sum > capacity){
                return false;
            }
        }
        
        return true;
    }
};
