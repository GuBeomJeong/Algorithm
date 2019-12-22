# Maximum Gap
가장 큰 값과 가장 작은 값의 차이의 평균을 낸다. 그리고 그 평균의 값으로 각각의 값들을 나누면 그 값들이 어느 범위에 속하는지 알 수 있다.   
그 범위는 N-1개이기때문에 N-1개의 범위내에서 가장 큰 차이를 찾을 수 있다. 해당 범위에서 가장 큰 값과 다음 범위에서 가장 작은 값의
 차이를 구하여 그 차이가 제일 큰 값이 답이 되며, O(N) 으로 풀 수 있다.   
 avg 값을 double로 하면 n개로 찾을 수 있다. int로 하면 n 보다 조금 더 많은 개수가 필요할 수 있다.
``` C++
class Solution {
public:
	int maximumGap(vector<int>& nums) {

		int n = nums.size();

		if (n <= 1) {
			return 0;
		}

		int maxValue = 0;
		int minValue = INT_MAX;

		int value;

		for (int i = 0; i < n; i++) {
			value = nums[i];

			if (value > maxValue) {
				maxValue = value;
			}

			if (value < minValue) {
				minValue = value;
			}
		}

		if (maxValue == minValue) {
			return 0;
		}

		int avg = (maxValue - minValue) / (n-1);
        
        if (avg == 0) {
			avg = 1;
		}
        
		int size = (maxValue - minValue) / avg + 1;
        
		vector<int> maxDiv(size, 0);
		vector<int> minDiv(size, INT_MAX);
		
		int idx;

		for (int i = 0; i < n; i++) {
			value = nums[i];
			idx = (value - minValue) / avg;

			if (value > maxDiv[idx]) {
				maxDiv[idx] = value;
			}

			if (value < minDiv[idx]) {
				minDiv[idx] = value;
			}
		}

		int result = 0;
		int preMax = minValue;

		for (int i = 0; i < size; i++) {
			if (minDiv[i] == INT_MAX) {
				continue;
			}

			if (minDiv[i] - preMax > result) {
				result = minDiv[i] - preMax;
			}
			preMax = maxDiv[i];
		}

		return result;

	}
};
```
> Runtime: 8 ms, faster than 86.06% of C++ online submissions for Maximum Gap.
Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Maximum Gap.

## Sort 한 후 차이를 찾는 방법
``` c++
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        int result = 0;
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] > result){
                result = nums[i] - nums[i-1];
            }
        }
        
        return result;
        
        
    }
};
```
비교하려고 했는데 속도가 같다. 아마 input 값이 충분하지 않아서 그런 것 같다.   
Radix sort도 있는데 찾아봐야할 것 같다.
> Runtime: 8 ms, faster than 86.06% of C++ online submissions for Maximum Gap.
Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Maximum Gap.
