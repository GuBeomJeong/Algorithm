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
    bool isCousins(TreeNode* root, int x, int y) {
        int xh = 0;
        int yh = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int height = q.front().second;
            q.pop();
            
            if(node->val == x){
                xh = height;
                if(yh != 0){
                    break;
                }
            }
            
            if(node->val == y){
                yh = height;
                if(xh!=0){
                    break;
                }
            }
            
            if(node->left && node->left->val == x && node->right && node->right->val == y){
                return false;
            }
            
            if(node->left && node->left->val == y && node->right &&  node->right->val == x){
                return false;
            }
            
            if(node->left)q.push({node->left,height+1});
            if(node->right)q.push({node->right,height+1});
        }
        
        return xh == yh;
    }
};