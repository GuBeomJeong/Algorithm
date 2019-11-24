# Word Ladder II

글자수의 합을 26으로 나눈 것을 index로 저장하면 index -1 , index , index + 1 에는 무조건 한글자 차이나는 값들이 있을 수 밖에 없다.    
그 후 bfs와 여러 조건들을 확인하면서 문제를 풀었고 빠를거라고 생각했지만 매우 느렸다.   
하지만 개선의 여지가 있다
``` c++
class Solution {
public:
    
    vector<vector<string>> result;
    vector<vector<int>> pre;
    
    bool check(string str1,string str2){
        
        bool diff = false;
        
        for(int i=0;i<str1.size();i++){
            if(str1[i] != str2[i]){
                if(diff){
                    return false;
                }
                diff = true;
            }
        }
        
        return diff;
        
    }
    
    void makeResult(vector<string>& wordList,vector<string> v,string beginWord,int idx){
        
        int curIdx = idx;
        
        while(curIdx != -1){
            
            v.push_back(wordList[curIdx]);
            
            for(int i = 1; i < pre[curIdx].size(); i++){
                makeResult(wordList,v,beginWord,pre[curIdx][i]);
            }
            
            curIdx = pre[curIdx][0];
            
        }
        
        v.push_back(beginWord);
        reverse(v.begin(),v.end());
        
        result.push_back(v);
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        if(check(beginWord,endWord)){
            vector<string> v;
            v.push_back(beginWord);
            v.push_back(endWord);
            result.push_back(v);
            return result;
        }
        
        int n = wordList.size();
        int len = 0;
        int sum = 0;
        int idx = 0;
        
        pre.resize(n);
        vector<vector<int>> save(n);
        vector<int> sums(n);
        bool isEnd = false;
        
        for(int i=0;i< n;i++){
            len = wordList[i].size();
            sum = 0;
            if(endWord.compare(wordList[i]) == 0 ){
                isEnd = true;
                continue;
            }
            for(int j = 0;j<len;j++){
                sum += (wordList[i][j] - 'a');
            }
            save[sum/26].push_back(i);
            sums[i] = sum/26;
        }
        
        if(!isEnd){
            
            return result;
        }
        
        queue<pair<int,int>> q;
        vector<bool> visit(n,false);
        
        sum = 0;
        for(int i=0;i<beginWord.size();i++){
            sum += (beginWord[i] - 'a');
        }
        
        idx = sum / 26;
        
        int answerCnt = n+1;
        
        for(int i = idx - 1 ; i <= idx + 1; i++){
            if(i >= 0 && i < n){
                for(int j=0;j<save[i].size();j++){
                    int next = save[i][j];
                    string str = wordList[next];
                    if(check(beginWord,str)){
                        q.push({next, 1});
                        pre[next].push_back(-1);
                        visit[next] = true;
                    }
                }
            }
        }
        
        int preCnt = 0;
        vector<int> temp;
        vector<bool> is(n,false);

        
        while(!q.empty()){
            int curIdx = q.front().first;
            int cnt = q.front().second;
            q.pop();
                  
            string cur = wordList[curIdx];
            idx = sums[curIdx];
            
            if(is[curIdx]){
                continue;
            }
            
            is[curIdx] = true;
            
            if(cnt != preCnt){
                for(int i = 0;i < temp.size() ; i++){
                    visit[temp[i]] = true;
                }
                temp.clear();
            }
            preCnt = cnt;
            
            if(cnt > answerCnt){
                break;
            }
            
            if(check(cur,endWord)){
                
                answerCnt = cnt;
                vector<string> v;
                v.push_back(endWord);
                
                makeResult(wordList,v,beginWord,curIdx);
                continue;
            }
            
            
            for(int i = idx - 1 ; i <= idx + 1; i++){
                
                if(i >= 0 && i < n){
                    for(int j=0;j<save[i].size();j++){
                        int next = save[i][j];
                        if(visit[next]){
                            continue;
                        }
                        string str = wordList[next];
                        if(check(cur,str)){
                            q.push({next,cnt+1});
                            pre[next].push_back(curIdx);
                            temp.push_back(next);
                        }
                    }
                }
            }
            
        }
        
        return result;
        
        
        
    }
};
```
> Runtime: 1720 ms, faster than 5.19% of C++ online submissions for Word Ladder II.
Memory Usage: 14.8 MB, less than 95.00% of C++ online submissions for Word Ladder II.
Next challenges:
