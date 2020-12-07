class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        int result = n + 1;
        deque<int> l;
        
        for(int i=0;i<n;i++){
            
            if(i > 0){
                A[i] += A[i-1];
            }
            
            if(A[i] >= K){
                if(result > i + 1){
                    result = i+1;
                }
            }
            
            while(l.size() > 0 && A[i] - A[l.front()] >= K){
                if(result > i - l.front()){
                    result = i - l.front();
                }
                l.pop_front();
            }
            
            while(l.size() > 0 && A[i] <= A[l.back()]){
                l.pop_back();
            }
            
            l.push_back(i);
        }
        
        if(result == n+1){
            result = -1;
        }
        return result;
        
    }
};