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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        vector<int> result;
        TreeNode* node = root;
        
        while(node != 0 || !s.empty()){
            
            if(node){
                s.push(node);
                node = node->left;
            }else{
                node = s.top();
                s.pop();
                
                result.push_back(node->val);
                node = node->right;
            }
        }
        
        return result;
    }
};