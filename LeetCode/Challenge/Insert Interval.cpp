class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int s = newInterval[0];
        int e = newInterval[1];
        int index = 0;
        while(index < intervals.size() && intervals[index][1] < s){
            res.push_back(intervals[index++]);
        }
        while(index < intervals.size() && intervals[index][0] <= e){
            s = min(s, intervals[index][0]);
            e = max(e, intervals[index][1]);
            index++;
        }
        vector<int> temp(2);
        temp[0] = s;
        temp[1] = e;
        res.push_back(temp);
        while(index < intervals.size()){
            res.push_back(intervals[index++]);
        }
        return res;
    }
};

