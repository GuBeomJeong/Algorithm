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
    
    int find(TreeNode* root){
        int left = 0;
        int right = 0;
        int ret = 0;
        
        if(root->left){
            left = find(root->left);
            if(left == 0){
                return 0;
            }
        }
        
        if(root->right){
            right = find(root->right);
            if(right == 0){
                return 0;
            }
        }
        
        if(abs(left-right) > 1){
            return 0;
        }
        
        return max(ret,max(left,right)) + 1;
    }
    
    
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        return find(root);
    }
};