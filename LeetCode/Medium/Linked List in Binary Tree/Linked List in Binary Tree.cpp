/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> nodes;
    vector<int> list;
    
    bool compare(vector<int> &a,vector<int>& b){
        if(a.size() > b.size()){
            return false;
        }
        
        int a_idx = a.size()-1;
        int b_idx = b.size()-1;
        
        while(a_idx){
            if(a[a_idx--] != b[b_idx--]){
                return false;
            }
        }
        
        return true;
    }
    
    bool find(TreeNode* node){
        
        if(node == 0){
            return false;
        }
        
        nodes.push_back(node->val);

        if(node->val == list[list.size() - 1]){
            if(compare(list,nodes)){
                return true;
            }
        }
        
        
        if(find(node->left)){
            return true;
        }
               
        if(find(node->right)){
            return true;
        }
               
        nodes.pop_back();
        
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* node = head;
        
        while(node){
            list.push_back(node->val);
            node = node->next;
        }
        
        return find(root);
    }
};