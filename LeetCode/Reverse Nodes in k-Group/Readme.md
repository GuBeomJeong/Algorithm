# Reverse Nodes in k-Group

그냥 linked list 순서 바꾸는 문제, 특이점은 없다.
``` c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k==1){
            return head;
        }
        
        ListNode* node = head;
        ListNode* temp;
        ListNode* preLast = 0;
        ListNode* firstHead = 0;
        
        while(1){
            
            temp = node;
            
            for(int i=0;i<k;i++){
                if(temp == 0){
                    if(firstHead == 0){
                        return head;
                    }
                    return firstHead;
                }
                temp = temp->next;
            }
            
            for(int i=0;i<k-1;i++){
                temp = node->next->next;
                node->next->next = head;
                head = node->next;
                node->next = temp;
            }
            
            if(firstHead == 0){
                firstHead = head;
            }
            
            if(preLast != 0){
                preLast->next = head;
            }
            
            preLast = node;
            node = node->next;
            head = node;
        }     
        
        return firstHead;
    }
};

```

> faster than 8.11%   
`if(k == 1) 전 후`   
>Runtime: 20 ms, faster than 70.98% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Reverse Nodes in k-Group.
Next challenges:
