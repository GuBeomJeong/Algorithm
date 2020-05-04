class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        
        if( n == 0){
            return true;
        }
        
        int i = 0;
        int j = 0;
        
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        
        while(i < n && j < m){
            if(ransomNote[i] == magazine[j]){
                i++;
                if(i == n){
                    return true;
                }
            }
            j++;
        }
        
        return false;
    }
};