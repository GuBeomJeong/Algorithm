# 풀이
공간 O(N)

```C++
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
class BSTIterator {
public:
    
    vector<int> arr;
    int idx = 0;
    
    void inorder(TreeNode* root){
        if(root->left){
            inorder(root->left);
        }
        arr.push_back(root->val);
        if(root->right){
            inorder(root->right);
        }
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

공간 O(H) 

```C++
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
class BSTIterator {
public:
    
    vector<TreeNode*> stack;
    
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        stack.push_back(cur);
        while(cur->left){
            stack.push_back(cur->left);
            cur = cur->left;
        }
    }
    
    int next() {
        TreeNode* cur = stack.back();
        stack.pop_back();
        int ret = cur->val;
        if(cur->right){
            cur = cur->right;
            stack.push_back(cur);
            while(cur->left){
                stack.push_back(cur->left);
                cur = cur->left;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```