class Trie{
public:
    Trie* child[26];
    bool last = false;
    
    void insert(string s){
        Trie* trie = this;
        
        for(auto c : s){
            if(!trie->child[c-'a']){
                trie->child[c-'a'] = new Trie();
            }
            
            trie = trie->child[c-'a'];
        }
        
        trie->last = true;
    }
};

class Solution {
public:
    
    Trie* root;
    vector<bool> dp;
    
    bool find(Trie* trie,string& s,int idx){
        
        if(idx == s.size()){
            return trie->last;
        }
        
        if(trie->child[s[idx] - 'a']){
            if(find(trie->child[s[idx] - 'a'],s,idx+1)){
                return true;
            }
        }
        
        if(trie->last){
            if(!dp[idx]){
                return false;
            }
            if(find(root,s,idx)){
                return true;
            }
            dp[idx] = false;
        }
        
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        dp.resize(s.size(),true);
        
        for(auto word: wordDict){
            root->insert(word);
        }
        
        return find(root,s,0);
    }
};
