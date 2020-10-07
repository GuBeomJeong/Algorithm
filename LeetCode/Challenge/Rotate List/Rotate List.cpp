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