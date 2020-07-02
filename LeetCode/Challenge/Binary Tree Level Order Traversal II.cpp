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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        vector<vector<int>> result;
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if(result.size() != depth){
                result.push_back(vector<int>());
            }
            
            result[depth-1].push_back(node->val);
            
            if(node->left){
                q.push({node->left,depth+1});
            }
            if(node->right){
                q.push({node->right,depth+1});
            }
        }
        
        int h = result.size();
        vector<vector<int>> real(h);
        for(int i=0;i<h;i++){
            for(int j=0;j<result[h-i-1].size();j++){
                real[i].push_back(result[h-i-1][j]);
            }
        }
        return real;
    }
};