class Solution {
public:
    
    int n;
        
    int start[26];
    int end[26];
    vector<int> result;
    bool check[26][26];    
    
    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }
    
    vector<string> maxNumOfSubstrings(string s) {
        n = s.size();
        
        for(int i = 0;i<26;i++){
            start[i] = -1;
            end[i] = -1;
            for(int j=0;j<26;j++){
                check[i][j] = false;
            }
        }
        
        for(int i=0;i<n;i++){
            char c = s[i] - 'a';
            if(start[c] == -1){
                start[c] = i;
                end[c] = i;
            }else{
                end[c] = i;
            }
        }
        
        for(int i=0;i<n;i++){
            char c = s[i] - 'a';
            
            for(int a = 0; a < 26; a++){
                if(start[a] < i && end[a] > i){
                    check[a][c] = true;
                }
            }
        }
        
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(check[i][j]){
                    start[i] = min(start[i],start[j]);
                    end[i] = max(end[i],end[j]);
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(check[i][j]){
                    start[i] = min(start[i],start[j]);
                    end[i] = max(end[i],end[j]);   
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(check[i][j]){
                    start[i] = min(start[i],start[j]);
                    end[i] = max(end[i],end[j]);   
                }
            }
        }
        
        vector<string> result;
        vector<bool> visit(n+1,false);
        
        for(int i=0;i<26;i++){
            if(start[i] != -1 && !visit[start[i]]){
                result.push_back(s.substr(start[i],end[i] - start[i]+1));
                visit[start[i]] = true;
            }
            
        }
        
        sort(result.begin(),result.end(),cmp);
        
        vector<bool> a(26,false);
        vector<string> real;
        
        
        for(int i=0;i<result.size();i++){
            bool flag= false;
            for(int j=0;j<result[i].size();j++){
                if(a[result[i][j] -'a']){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                for(int j=0;j<result[i].size();j++){
                    a[result[i][j]-'a'] = true;
                }
                real.push_back(result[i]);
            }
        }
        
        return real;
        
    }
};
