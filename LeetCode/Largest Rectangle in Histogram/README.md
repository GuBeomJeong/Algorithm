# Largest Rectangle in Histogram
left[i] = 현재 index 의 높이보다 큰 값들의 왼쪽 경계   
right[i] = 현재 index의 높이보다 큰 값들의 오른쪽 경계   
해당 값을 타고 들어가는 방식으로 구현하여 바로 왼쪽 , 오른쪽 경계 값을 구할 수 있다.(union find 에서 바로 부모 붙여주는 거 생각하면 될 듯)   
따라서 현재 height[i] * (right[i] - left[i] + 1)이 답이 된다.