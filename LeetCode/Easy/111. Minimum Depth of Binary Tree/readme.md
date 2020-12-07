# 풀이
BFS로 하면 훨씬 빠를듯
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
```
> Runtime: 332 ms, faster than 6.65% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 146 MB, less than 9.46% of C++ online submissions for Minimum Depth of Binary Tree.