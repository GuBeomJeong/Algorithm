class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        
        values = list(enumerate(A))
        values.sort(key=lambda x:x[1])
        size = len(values)
        
        flag = False
        for i in range(size-1, -1, -1):
            idx, value = values[i]
            if flag:
                if idx != i + 1: 
                    return False  
                flag = False
            elif idx == i-1:
                flag = True
            elif idx == i:
                flag = False
            else:
                return False
        
        return True
            
                
            
            