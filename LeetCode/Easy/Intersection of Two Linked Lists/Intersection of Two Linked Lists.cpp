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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        int nA = 0;
        int nB = 0;
        
        
        while(nodeA){
            nodeA = nodeA->next;
            nA++;
        }
        
        while(nodeB){
            nodeB = nodeB->next;
            nB++;
        }
        
        nodeA = headA;
        nodeB = headB;
        
        if(nA < nB){
            for(int i=0;i< nB - nA; i++){
                nodeB = nodeB->next;
            }
        }else{
            for(int i=0;i< nA - nB; i++){
                nodeA = nodeA->next;
            }
        }
        
        while(nodeA && nodeB && nodeA != nodeB){
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        
        return nodeA;
    }
};