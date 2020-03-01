class Solution {
public:
    
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> info;
        vector<int> result(n);
        for(int i=0;i<n;i++){
            info.push_back({nums[i],i});
        }
        
        sort(info.begin(),info.end());
        
        int prev = -1;
        
        for(int i=0;i<n;i++){
            if(i>0 && info[i].first == info[i-1].first){
                result[info[i].second] = result[info[i-1].second];
            }else{
                result[info[i].second] = i;
            }
            
        }
        
        return result;
    }
};