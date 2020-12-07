class Solution {
public:
    
    static bool cmp(string& a, string& b){
        
        int an = a.size();
        int bn = b.size();
        int a_idx = 0;
        int b_idx = 0;
        
        while(a[a_idx] == b[b_idx]){
            a_idx = (a_idx+1) % an;
            b_idx = (b_idx+1) % bn;
            
            if(a_idx == an - 1 && b_idx == bn - 1){
                return a[a_idx] > b[b_idx];
            }
            
        }
        
        return a[a_idx] > b[b_idx];
    }
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> values;
        bool zero = true;
        
        for(auto num : nums){
            if(num != 0){
                zero = false;
            }
            values.push_back(to_string(num));
        }
        
        if(zero){
            return "0";
        }
        
        sort(values.begin(),values.end(),cmp);
        string result = "";
        
        for(auto str : values){
            result += str;
        }
        
        return result;
    }
};
