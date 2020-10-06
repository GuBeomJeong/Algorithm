class Solution {
public:
    
    bool is_palindrome(string& str){
        
        int n = str.size();
        
        for(int i=0;i<n/2;i++){
            if(str[i] != str[n-i-1]){
                return false;
            }
        }
        
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        
        vector<vector<pair<string,int>>> alpha(26);
        vector<vector<int>> result;
        int blank = -1;
        
        vector<vector<bool>> is_check(n,vector<bool>(n,false));
        
        for(int i =0; i < n ; i++){
            string word = words[i];
            if(word == ""){
                blank = i;
                continue;
            }
            alpha[word[0] - 'a'].push_back({word,i});
        }
        
        for(int i =0; i< n; i++){
            string word = words[i];
            if(word == ""){
                continue;
            }
            
            vector<pair<string,int>> candis = alpha[word.back() - 'a'];
            
            for(auto candi : candis){
                
                int index = candi.second;
                
                if(i == index){
                    continue;
                }
                
                if(is_check[i][index]){
                    continue;
                }
                
                is_check[index][i] = true;
                is_check[i][index] = true;
                
                string temp = word + candi.first;
                if(is_palindrome(temp)){
                    result.push_back({i,index});
                }
                
                temp = candi.first + word;
                                
                if(is_palindrome(temp)){
                    result.push_back({index,i});
                }
            }
        }
        
        if(blank != -1){
            for(int i=0;i<n;i++){
                if(i != blank && is_palindrome(words[i])){
                    result.push_back({i,blank});
                    result.push_back({blank,i});
                }
            }
        }
        
        return result;
    }
};