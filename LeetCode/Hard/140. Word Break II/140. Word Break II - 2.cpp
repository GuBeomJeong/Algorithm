class Solution {
public:
    class Trie{
        public:
        Trie* alpha[26];
        bool fin = false;
        int num = 0;
        int cnt = 1;
        
        Trie(){
            for(int i=0;i<26;i++){
                alpha[i] = 0;
            }
        }
        
        void add(string str){
            
            int n = str.size();
            
            if(alpha[str[0]- 'a'] == 0){
                alpha[str[0] - 'a'] = new Trie();
                alpha[str[0] - 'a']->num = cnt;
                cnt++;
            }
            
            Trie* node = alpha[str[0] - 'a'];
            
            for(int i=1;i<n;i++){
                if(node->alpha[str[i] - 'a'] == 0){
                    node->alpha[str[i] - 'a'] = new Trie();
                    node->alpha[str[i] - 'a']->num = cnt;
                    cnt++;
                }
                node = node->alpha[str[i] - 'a'];
            }
            
            node->fin = true;
        }
    };
    
    Trie *trie = new Trie();
    int n,len;
    vector<string> result;
    vector<vector<bool>> dp;
    
    bool find(string& s,int idx,Trie* cur,string str){
        
        if(idx == len){
            if(cur->fin){
                result.push_back(str);
                return true;
            }
            return false;
        }
        
        if(!dp[idx][cur->num]){
            return false;
        }
        
        bool ret = false;
        
        if(cur->alpha[s[idx] - 'a']){
            ret = find(s,idx+1,cur->alpha[s[idx] - 'a'],str + s[idx]);
        }
        
        if(cur->fin && trie->alpha[s[idx] - 'a'] && dp[idx][0]){
            ret = ret | find(s,idx,trie,str+' ');    
        }
        
        return dp[idx][cur->num] = ret;
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = s.size();
        n = wordDict.size();
         
        for(int i=0;i<n;i++){
            trie->add(wordDict[i]);
        }
        
        dp.resize(len,vector<bool>(trie->cnt,true));
        
        Trie* node = trie;
        
        find(s,0,node,"");
        
        return result;
    }
};