class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        int i = 0;
        while(i<n){
            if(s[i] == ' '){
                i++;
                continue;
            }
            int j = i+1;
            while(j < n && s[j] != ' '){
                j++;    
            }
            
            int end = j - 1;
            
            while(i < end){
                char temp = s[i];
                s[i] = s[end];
                s[end] = temp;
                i++;
                end--;
            }
            
            i = j;
        }
        
        
        int blank = 0;
        bool prev= true;
        for(int i =0;i<n;i++){
            if(s[i] == ' '){
                if(prev){
                    blank++;                
                }else{
                    s[i-blank] = s[i];
                }
                prev = true;
            }else{
                s[i-blank] = s[i];
                prev = false;
            }
        }
        
        for(int i=0;i<blank;i++){
            s.pop_back();
        }
        
        while(s.size() > 0 && s.back() == ' '){
            s.pop_back();
        }
        
        n = s.size();
                
        i=0;
        int j = n-1;
        
        while(i<j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        
        
        return s;
    }
};