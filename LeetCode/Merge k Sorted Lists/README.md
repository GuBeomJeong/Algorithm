# Merge k Sorted Lists
heap을 이용하여 가장 작은 값을 logk로 찾았다.

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
    class Compare{
        public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }    
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        
        int k = lists.size();
        ListNode* head = 0;
        ListNode* node = 0;
        ListNode* tail = 0;
        
        for(int i=0;i<k;i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }
        
        while(!pq.empty()){
            node = pq.top();
            pq.pop();
            
            if(node->next){
                pq.push(node->next);
            }
                    
            if(head == 0){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = node;
            }
        }
        
        return head;
    }
};
```
>Runtime: 32 ms, faster than 48.26% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 12.6 MB, less than 5.95% of C++ online submissions for Merge k Sorted Lists.
Next challenges:
