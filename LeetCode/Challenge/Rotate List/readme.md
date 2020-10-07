# Rotate List
직접 다 돌릴필요가 없다.    
head와 tail을 연결하고 이동해야할 지점까지 가서 두 노드를 끊으면 된다.   
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next){
            return head;
        }
        
        ListNode* node = head;
        int cnt = 1;
        
        while(node->next){
            cnt++;
            node = node->next;
        }
        
        node->next = head;
        node = head;
        k = k % cnt;
        
        for(int i=0;i< cnt - k - 1; i++){
            node = node->next;
        }
        
        head = node->next;
        node->next = 0;
        
        return head;
        
    }
};
```
> Your runtime beats 82.32 % of cpp submissions.