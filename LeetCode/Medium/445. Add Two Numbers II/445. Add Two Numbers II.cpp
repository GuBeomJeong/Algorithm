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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> value1;
        vector<int> value2;
        
        while(l1){
            value1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            value2.push_back(l2->val);
            l2 = l2->next;
        }
        
        int idx1 = value1.size() - 1;
        int idx2 = value2.size() - 1;
        int up = 0;
        
        vector<int> result;
        
        while(idx1 >= 0 && idx2 >= 0){
            int sum = value1[idx1] + value2[idx2] + up;
            up = sum >=10;
            result.push_back(sum % 10);
            idx1--;
            idx2--;
        }
    
        
        while(idx1 >= 0){
            result.push_back((value1[idx1] + up) % 10);
            up = (value1[idx1]+up) >= 10;
            idx1--;
        }
        
        while(idx2 >= 0){
            result.push_back((value2[idx2]+up) % 10);
            up = (value2[idx2]+up) >= 10;
            idx2--;
        }
        
        if(up){
            result.push_back(1);
        }
       
        int size = result.size();
        
        if(size == 1){
            return new ListNode(result[0]);
        }
        
        ListNode* head = new ListNode(result[size-1]);
        ListNode* node = head;
        
        for(int i=size-2;i>=0;i--){
            node->next = new ListNode(result[i]);
            node = node->next;
        }
        
        return head;
       
    }
};