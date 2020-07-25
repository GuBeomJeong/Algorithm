class Solution {
public:
    
    vector<int> parent;
    vector<int> size;
    
    int gcd(int a, int b){
        int c;
        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    
    int find(int a){
        if(parent[a] == a){
            return a;
        }
        
        return parent[a] = find(parent[a]);
    }
    
    void merge(int a,int b){
        
        a = find(a);
        b = find(b);
        
        if(a == b){
            return;
        }
        
        parent[a] = b;
    }
    
    int largestComponentSize(vector<int>& A) {
        
        int n = A.size();
        parent.resize(100001);
        size.resize(100001,0);
        
        for(int i=0;i<100001;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<n;i++){
            
            int limit = sqrt(A[i]);
            for(int k=2;k<=limit;k++){
                if(A[i] % k == 0){
                    merge(A[i],k);
                    merge(A[i],A[i]/k);
                }
            }
        }
        
        int result = 0;
        for(int i=0;i<n;i++){
            int p = find(A[i]);
            size[p]++;
            if(size[p] > result){
                result = size[p];
            }
        }
        
        return result;
    }
};