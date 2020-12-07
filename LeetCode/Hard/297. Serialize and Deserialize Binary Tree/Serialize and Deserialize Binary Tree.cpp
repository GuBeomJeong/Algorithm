/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    
    void serial(TreeNode* root, string& result){
        if (root) {
            result += to_string(root->val) + ',';
            serial(root->left, result);
            serial(root->right, result);
        } else {
            result += "n,";
        }
    }
    
    TreeNode* deserial(pair<string,int> &result) {
        string val = "";
        int &idx = result.second;
        
        while(result.first[idx] != ','){
            val += result.first[idx];
            idx++;
        }
        idx++;
        
        if (val == "n")
            return 0;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserial(result);
        root->right = deserial(result);
        return root;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serial(root, result);
        cout << result;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        pair<string,int> result = {data,0};
        return deserial(result);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));