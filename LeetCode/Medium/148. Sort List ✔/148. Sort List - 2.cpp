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