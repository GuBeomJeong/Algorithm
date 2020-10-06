class Solution {
public:
    
    bool is_palindrome(string& str, int start, int end){
        while (start < end) {
            if (str[start++] != str[end--])
                return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> map;
        vector<vector<int>> result;
        
        for(int i=0;i<n;i++){
            map[words[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            int word_size = words[i].size();
            for(int j=0;j<word_size;j++){
                if(is_palindrome(words[i],j,word_size-1)){
                    string temp = words[i].substr(0,j);
                    reverse(temp.begin(),temp.end());
                    if(map.find(temp) != map.end() && i != map[temp]){
                        result.push_back({i,map[temp]});
                    }
                }
                
                if(is_palindrome(words[i],0,j)){
                    string temp = words[i].substr(j+1,word_size - j - 1);
                    reverse(temp.begin(),temp.end());
                    if(map.find(temp) != map.end() && i != map[temp]){
                        result.push_back({map[temp],i});
                    }
                }
            } 
            
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            if(map.find(temp) != map.end() && i != map[temp]){
                result.push_back({i,map[temp]});
            }
        }
        
        return result;
    }
};