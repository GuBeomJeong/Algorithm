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
    
    ListNode* quicksort(ListNode* start, ListNode* pre_start, ListNode* end){
        if(start && end && start->next && start != end){
            ListNode* pivot = start;
            ListNode* node = start->next;
            ListNode* pre = start;
            ListNode* pre_pivot = 0;
            
            while(node && node != end->next){
                if(node->val < pivot->val){
                    pre->next = node->next;
                    if(pre_pivot){
                        pre_pivot->next = node;
                        node->next = pivot;
                        pre_pivot = node;
                    }else{
                        pre_pivot = node;
                        pre_pivot->next = pivot;
                        start = pre_pivot;
                        if(pre_start){
                            pre_start->next = start;
                        }
                    }
                    node = pre->next;
                }else{
                    pre = node;
                    node = node->next;
                }
            }
            
            if(start != pivot){
                start = quicksort(start,pre_start, pre_pivot);
            }
            quicksort(pivot->next,pivot, end);
        }
        
        return start;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head){
            return 0;
        }
        
        ListNode* tail = head;
        
        while(tail->next){
            tail = tail->next;
        }
        
        head = quicksort(head,0,tail);
        
        return head;
    }
};