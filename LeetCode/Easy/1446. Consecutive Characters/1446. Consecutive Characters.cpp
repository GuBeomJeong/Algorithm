class Solution {
public:
    int maxPower(string s) {
        int result = 1;
        int prev = 0;
        int cnt = 0;
        
        for(auto num : s){
            if(prev == num){
                cnt++;
                if(cnt > result){
                    result = cnt;
                }
            }else{
                prev = num;
                cnt = 1;
            }
        }
        
        return result;
    }
};