class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ret = 0

        stack = []
        stack.append(-1)

        for idx, c in enumerate(s):
            if c == '(':
                stack.append(idx)
            else:
                stack.pop()
                if len(stack) != 0:
                    ret = idx - stack[-1] if idx - stack[-1] > ret else ret 
                else:
                    stack.append(idx)
                    
        return ret
