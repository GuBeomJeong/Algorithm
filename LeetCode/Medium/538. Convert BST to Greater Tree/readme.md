# 풀이
오른쪽 자식과 왼쪽 자식이 있는지에 따라서 다르게만 해주면 된다.    
```c++
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
    int convert(TreeNode* node, int value){
        
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        int right_val = 0;
        int left_val = 0;
        
        if(right){
            right_val = convert(right,value);
        }
        
        node->val = right_val ? node->val + right_val : node->val + value;
        
        if(left){
            left_val = convert(left,node->val);
        }
        
        return left_val ? left_val : node->val;
        
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return root;
        }
        convert(root,0);
        return root;
    }
};
```
