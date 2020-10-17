# 187. Repeated DNA Sequences
4의 지수로 구분하여 map을 썼다.   
```c++
class Solution {
public:
    
    int convert(char c){
        if(c == 'A'){
            return 0;
        }
        if(c == 'C'){
            return 1;
        }
        if(c == 'G'){
            return 2;
        }
        if(c == 'T'){
            return 3;
        }
        return 0;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        
        int sum = 0;
        int pos = 1;
        
        unordered_map<int,int> value;
        
        int idx = 0;
        
        while(idx < 10){
            sum += convert(s[idx]) * pos;
            pos *= 4;
            idx++;
        }
        
        value[sum] = -1;
        pos /= 4;
                
        while(idx < n){
            sum -= convert(s[idx-10]);
            sum /= 4;
            sum += convert(s[idx]) * pos;
            if(value.find(sum) != value.end()){
                value[sum] = idx;
            }else{
                value[sum] = -1;
            }
            idx++;
        }
        
        vector<string> result;
        
        for(auto iter : value){
            if(iter.second != -1){
                result.push_back(s.substr(iter.second-9,10));
            }
        }
        
        return result;
    }
};
```