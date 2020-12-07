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
    int result = 0;
    
    int find(TreeNode* root) {
        
        int ret = 0;
        int left_val = 0;
        int right_val = 0;
        
        if(root->left){
            left_val = find(root->left);
        }
        if(root->right){
            right_val = find(root->right);
        }
        
        int val = root->val;        
        result += abs(right_val-left_val);
        
        return left_val + right_val + val;
    }
    
    int findTilt(TreeNode* root){
        if(!root){
            return 0;
        }
        find(root);
        return result;
    }
};