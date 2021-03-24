class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        vector<pair<int,int>> A_pair;
        vector<pair<int,int>> B_pair;
        
        for(int i=0;i<n;i++){
            A_pair.push_back({A[i],i});
            B_pair.push_back({B[i],i});
        }
        
        
        sort(A_pair.begin(), A_pair.end());
        sort(B_pair.begin(), B_pair.end());
        
        int a=0;
        int b=0;
        
        vector<int> result(n,0);
        vector<pair<int,int>> skip;
        
        
        while(a < n){
            if(A_pair[a].first <= B_pair[b].first){
                skip.push_back({A_pair[a].first, A_pair[a].second});
            }
            else{
                result[B_pair[b].second] = A_pair[a].first;
                b++;
            }
            a++;
        }
        
        int idx = 0;
        
        while(b<n){
            result[B_pair[b].second] = skip[idx].first;
            b++;
            idx++;
        }
        
        return result;
        
    }
};