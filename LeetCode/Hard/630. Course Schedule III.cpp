class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        
        sort(courses.begin(),courses.end(),cmp);
        
        int sum = 0;
        priority_queue<pair<int,int>> pq;
        
        for(auto course : courses){
            if(sum + course[0] <= course[1]){
                sum += course[0];
                pq.push({course[0],course[1]});
            }else{
                if(pq.empty()){
                    continue;
                }
                int d = pq.top().first;
                int l = pq.top().second;
                if(course[0] > d){
                    continue;
                }
                if ( sum - d + course[0] <= course[1]){
                    pq.pop();
                    sum -= d;
                    sum += course[0];
                    pq.push({course[0],course[1]});
                }
            }
        }
        
        return pq.size();
        
        
    }
};
