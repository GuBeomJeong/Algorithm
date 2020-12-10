class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool up = true;
        int n = arr.size();
        
        if(n == 1){
            return false;
        }
        
        if(arr[1] <= arr[0]){
            return false;
        }
        
        for(int i=1;i< n;i++){
            if(arr[i] == arr[i-1]){
                return false;
            }
            
            if(arr[i] > arr[i-1]){
                if(!up){
                    return false;
                }
            }
            if(arr[i] < arr[i-1]){
               up = false;
            }
        }
        
        return !up;
    }
};