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
    
    vector<int> result;
    
    int preorder(TreeNode* root, vector<int>& voyage, int idx){
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if(!left && !right){
            return idx;
        }
        
        if(left){
            
            if(left->val == voyage[idx]){
                idx = preorder(left,voyage,idx + 1);
            }else{
                if(right && right->val == voyage[idx]){
                    result.push_back(root->val);
                    TreeNode* temp = left;
                    left = right;
                    right = temp;
                    
                    idx = preorder(left,voyage,idx + 1);
                }else{
                    return -1;
                }
            }
        }
        
        if(idx == -1){
            return -1;
        }
        
        if(right){
            if(right->val == voyage[idx]){
                idx = preorder(right, voyage, idx + 1);
            }
            else{
                return -1;
            }
        }else{
            return idx;
        }
        
        if(idx == -1){
            return -1;
        }
        
        return idx;
        
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int ret = preorder(root,voyage,1);
        if(ret == -1){
           return vector<int>(1,-1); 
        }
        
        return result; 
    }
};