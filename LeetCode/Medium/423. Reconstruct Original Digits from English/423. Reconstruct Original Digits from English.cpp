class Solution {
public:
    string originalDigits(string s) {
        int count[26];
        char number[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};        
        
        int result[10];
        
        for(int i=0;i<26;i++){
            count[i] = 0;
        }
        
        for(int i=0;i<10;i++){
            result[i] = 0;
        }
        
        for(char c : s){
            count[c-'a']++;
        }
        
        result[0] = count['z'-'a'];
        result[2] = count['w' - 'a'];
        result[4] = count['u' - 'a'];
        result[6] = count['x' - 'a'];
        result[8] = count['g' - 'a'];
        
        
        for(int i=0;i<10;i++){
            for(int j=0; number[i][j] != 0; j++){
                int c = number[i][j] - 'a';
                count[c] -= result[i];
            }
        }
        
        result[1] = count['o' - 'a'];
        result[3] = count['t' - 'a'];
        result[5] = count['f' - 'a'];
        result[7] = count['s' - 'a'];
        
        for(int i=1;i<9;i = i + 2){
            for(int j=0; number[i][j] != 0; j++){
                int c = number[i][j] - 'a';
                count[c] -= result[i];
            }
        }
        
        result[9] = count['i' - 'a'];
        
        string ret = "";
        for(int i=0;i<10;i++){
            for(int j=0;j<result[i];j++){
                ret += i + '0';
            }
        }
        
        return ret;
    }
};