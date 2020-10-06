/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        TreeNode* node = root;
        while(1){
            
            if(node->val > val){
                if(!node->left){
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            }else{
                if(!node->right){
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
        }
        
        return root; 
    }
};