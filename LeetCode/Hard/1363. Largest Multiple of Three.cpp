class Solution {
public:
    
    vector<int> result;
    
    bool solve(vector<int>& digits, int idx, int cnt, int limit, int sum){
        
        sum -= digits[idx];
        
        if(cnt == limit){
            if(sum %3 == 0){
                result.push_back(idx);
                return true;
            }
            return false;
        }
                
        for(int i = idx +1; i < digits.size(); i++){
            if(solve(digits,i,cnt+1,limit,sum)){
                result.push_back(idx);
                return true;
            }
        }
        
        return false;
        
    }
    
    string largestMultipleOfThree(vector<int>& digits) {
        
        int n = digits.size();
        
        int sum = 0;
        
        sort(digits.begin(),digits.end());
        
        for(auto digit : digits){
            sum += digit;
        }
        
        string ret = "";
        
        bool zero = true;
        
        if(sum % 3 == 0){
            for(int i = n-1; i >=0; i--){
                if(digits[i] != 0){
                    zero = false;
                }
                ret += digits[i] + '0';
            }
            if(zero){
                return "0";
            }
            return ret;
        }
        
        for(int i=1;i<n;i++){
            bool flag =false;
            for(int j=0;j<=n-i;j++){
                if(solve(digits,j,1,i,sum)){
                    flag= true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        
        if(result.empty()){
            return "";
        }
        zero = true;
        
        for(int i = n-1; i >= 0 ; i--){
            bool flag= false;
            for(auto remove : result){
                if(i == remove){
                    flag = true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            if(digits[i] != 0){
                zero = false;
            }
            ret += digits[i] + '0';
        }
        
        
        if(zero){
            return "0";
        }
        
        return ret;
        
        
    }
};
