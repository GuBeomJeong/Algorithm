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
    
    int result = 100001;
    
    void find(TreeNode* node, int depth){
        
        if(!node->left && !node->right){
            result = min(result, depth);
            return;
        }
        
        if(node->left){
            find(node->left,depth+1);
        }
        if(node->right){
            find(node->right,depth+1);
        }
    }
    
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        find(root,1);
        return result;
    }
};