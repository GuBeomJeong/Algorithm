class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        vector<int> left(n + 2,n);
        vector<int> right(n + 2,0);
        left[0] = 0;
        right[n+1] = 0;
        int result = 0;
        int max_idx = 0;
        
        for(int i=0;i<n;i++){
            
            if(light[i] > max_idx){
                max_idx = light[i];
            }
            
            right[light[i]] = light[i];
            left[light[i]] = light[i];
            
            if(left[light[i] - 1] != n){
                left[light[i]] = left[light[i] - 1];
            }
            
            if(right[light[i] + 1] != 0){
                right[light[i]] = right[light[i] + 1];
            }
            
            right[left[light[i]]] = right[light[i]];
            left[right[light[i]]] = left[light[i]];
            
            if(left[light[i] - 1] == 0 && right[light[i]] == max_idx){
                result++;
            }
        }
        
        return result;
        
        
    }
};