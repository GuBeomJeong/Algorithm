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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = 0;
        ListNode* node = head;
        int sum = 0;
        int plus = 0;
        
        while(l1 || l2){
            
            if(!head){
                head = new ListNode(0);
                node = head;
            }else{
                node->next = new ListNode(0);
                node = node->next;
            }
             
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            
            sum = l1_val + l2_val + plus;
            node->val = sum % 10;
            plus = sum / 10;
            
            l1 = l1 ? l1->next : 0;
            l2 = l2 ? l2->next : 0;
        }
        
        if(plus){
            node->next = new ListNode(1);
        }
        
        
        return head;
    }
};