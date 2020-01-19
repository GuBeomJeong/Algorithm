# Median of Two Sorted Arrays
두 정렬된 배열의 중간값을 찾는 문제.   
기본적으로 log(N+M)으로 풀어야하기 때문에 이분검색을 생각할 수 있다.   
가장 먼저 생각한 것은 값 하나를 기준으로 나누면 두 범위에 개수를 알 수 있기 때문에 중간 값이 어디에 속하는 지 알 수 있다.  
그럼 범위를 log 로 구할 수 있다. 하지만 여기서 범위를 찾는 것이 log이기 때문에 log^2 가 된다.   
   
log로 풀기위해서는 범위를 이분검색으로 찾아야 한다.   
핵심은 범위를 나누었을 때 왼쪽에서 가장 큰 값이 오른쪽에서 가장 작은 값보다 작아야 한다는 점이다.   
구현을 직접하지 못했는데 그 이유를 찾아보았다.   
1. 이분검색 스킬 부족   
2. 범위 값(N, N-1 등이 너무 햇갈리는 문제)   
3. 홀수, 짝수일 때 차이 + 하나의 배열이 전부 왼쪽에 속한 경우 + 구한 값 4개 중 어떤 것이 중간 값인지 결정하는 로직   
   
구현 스킬
1. 둘 중 길이가 큰 배열을 하나의 변수로 설정
2. 이분 검색 hi 를 N2 * 2로 잡은 점
3. L1,R1 등 알기 쉽게 변수를 미리 지정한 것

``` C++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        
        if(N1 < N2){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int lo = 0;
        int hi = N2 * 2;
        
        while(lo <= hi){
            int mid2 = (lo + hi) / 2;
            int mid1 = N1 + N2 - mid2;
            
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
            
            if(L1 > R2){
                lo = mid2 + 1;
            }else if(L2 > R1){
                hi = mid2 - 1;
            }else{
                return (max(L1,L2) + min(R1,R2)) / 2;
            }
        }
        
        return 0;
    }
};
```
> Runtime: 28 ms, faster than 17.92% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 9.6 MB, less than 88.66% of C++ online submissions for Median of Two Sorted Arrays.
Next challenges:
속도가 느리게 나왔다.
