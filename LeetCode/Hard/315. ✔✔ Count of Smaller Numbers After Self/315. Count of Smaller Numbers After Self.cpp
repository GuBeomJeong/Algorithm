class Solution {
public:
    
    vector<pair<int,int>> value;
    vector<int> result;
    vector<pair<int,int>> buf;
    
    void mergeSort(int s,int e){
        
        if(e-s < 1){
            return;
        }
        
        int m = (s + e) / 2;
        
        mergeSort(s,m);
        mergeSort(m+1,e);
        
        merge(s,m,e);
        return;
    }
    
    void merge(int s,int m,int e){
        
        int i = s;
        int j = m + 1;
        int idx = 0;
        int count = 0;
        
        while(i <= m && j <= e){
            
            if(value[i].first <= value[j].first){                
                buf[idx++] = value[i++];
                if(i <= m){
                     result[value[i].second] += count;
                }
            }
            
            if(value[i].first > value[j].first){
                count++;
                result[value[i].second]++;
                buf[idx++] = value[j++];
            }
        }
        
        while(i <= m){
            buf[idx++] = value[i++];
            if(i <= m){
                 result[value[i].second] += count;
            }
        }
        
        while(j <= e){
            buf[idx++] = value[j++];
        }
        
        for(int k = 0; k < idx ; k++){
            value[s + k] = buf[k];
        }
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        value.resize(n);
        result.resize(n,0);
        buf.resize(n);
        
        for(int i=0;i<n;i++){
            value[i] = {nums[i],i};
        } 
        
        mergeSort(0,n-1);
        
        return result;
    }
};