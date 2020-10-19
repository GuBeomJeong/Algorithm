# Sort List
Merge Sort

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
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* start = new ListNode(0);
        ListNode* pos = start;
        
        while(left && right){
            if(left->val < right->val){
                pos->next = left;
                left = left->next;
            }else{
                pos->next = right;
                right = right->next;
            }
            pos = pos->next;
        }
        
        while(left){
            pos->next = left;
            left = left->next;
            pos = pos->next;
        }
        
        while(right){
            pos->next = right;
            right = right->next;
            pos = pos->next;
        }
        
        return start->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == 0 || head->next == 0){
            return head;
        }
        
        ListNode* mid = head;
        ListNode* end = head;
        ListNode* pre = head;
        
        while(end && end->next){
            pre = mid;
            mid = mid->next;
            end = end->next->next;
        }
        
        pre->next = 0;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        
        return merge(l1,l2);
    }
};
```
> Runtime: 140 ms, faster than 11.05% of C++ online submissions for Sort List.
Memory Usage: 49.7 MB, less than 5.10% of C++ online submissions for Sort List.


# Sort List - solution 2 ( non recursive )
non recursive 한 풀이지만 똑같이 느리고 memory를 많이 쓴다. ???    
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
    
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next){
            return head;
        }
        
        ListNode* cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* left;
        ListNode* right;
        ListNode* tail;
        
        for(int step = 1; step < n ; step <<= 1){
            cur = dummy.next;
            tail = &dummy;
            
            while(cur){
                left = cur;
                right = split(left,step);
                cur = split(right,step);
                tail = merge(left,right,tail);
            }
        }
        
        return dummy.next;
        
    }
    
    ListNode* split(ListNode* node,int n){
        for(int i=1;node && i<n;i++){
            node = node->next;
        }
        
        if(!node){
            return 0;
        }
        ListNode* next = node->next;
        node->next = 0;
        return next;
    }
    
    ListNode* merge(ListNode* left, ListNode* right, ListNode* head){
        ListNode* cur = head;
        
        while(left && right){
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        
        cur->next = left ? left:right;
        while(cur->next){
            cur = cur->next;
        }
        return cur;
    }
    
    
};
```