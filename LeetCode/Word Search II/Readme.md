# Word Search II
Trie를 사용하여 다음 문자가 존재할때만 찾는 방법으로 구현했다.

``` c++
class Solution {
    
    public:
    class Trie{
        public:
        Trie* next[26];
        bool end = false;

        Trie(){
            memset(next,0,sizeof(next));
        }

        void push(string word){

            int len = word.size();
            Trie* trie = next[word[0] - 'a'];

            if(trie == 0){
                trie = new Trie();
                next[word[0] - 'a'] = trie;
            }

            for(int i = 1;i < len ; i++){
                if(trie->next[word[i] - 'a'] == 0){
                    trie->next[word[i]-'a'] = new Trie();
                }
                trie = trie->next[word[i] - 'a'];
            }

            trie->end = true;

        }
    };
    
    int n,m;
    vector<string> result;
    string current;
    Trie* trie;
    
    vector<vector<bool>> vsit;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void find(vector<vector<char>> &board,Trie* t, int x,int y){

        current.push_back(board[x][y]);
        vsit[x][y] = true;

        if(t->end){
            result.push_back(current);
            t->end = false;
        }

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && t->next[board[nx][ny] - 'a'] && !vsit[nx][ny]){
                find(board,t->next[board[nx][ny] - 'a'],nx,ny);
            }
        }

        vsit[x][y] = false;
        current.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        current = "";
        result.clear();
        
        int w = words.size();
        n = board.size();
        m = board[0].size();
        
        trie = new Trie();
    
        vsit.resize(n,vector<bool> (m,0));
        
        for(int i=0; i < w ; i++){
            trie->push(words[i]);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c = board[i][j];
                if(trie->next[c-'a']){
                    find(board,trie->next[c-'a'],i,j);
                }
            }
        }
     
        return result;
    }
};

auto ios = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
```

> Runtime: 32 ms, faster than 99.19% of C++ online submissions for Word Search II.
Memory Usage: 32.2 MB, less than 50.00% of C++ online submissions for Word Search II.
