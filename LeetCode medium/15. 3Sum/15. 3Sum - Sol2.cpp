class Solution {
public:
    
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,vector<pair<int,int>>> save;
        set<vector<int>> result;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                save[nums[i] + nums[j]].push_back({i,j});
            }
        }
        
        for(int i=0;i<n;i++){
            if(save.count(-nums[i])){
                
                for(int j=0;j<save[-nums[i]].size();j++){
                    pair<int,int> temp = save[-nums[i]][j];
                    
                    if(temp.first == i || temp.second == i){
                        continue;
                    }
                    int a,b,c;
                    
                    a = nums[i];
                    b = nums[temp.first];
                    c = nums[temp.second];
                    
                    if(a > c){
                        swap(a,c);
                    }
                    
                    if(a > b){
                        swap(a,b);
                    }
                    
                    if(b > c){
                        swap(b,c);
                    }
                    
                    result.insert({a,b,c});
                }
            }
        }
        
        return vector<vector<int>> (result.begin(),result.end());
    }
};