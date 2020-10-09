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
    
    vector<string> split(string input, char delimiter) {
        vector<string> answer;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }

        return answer;
    }
    
    void inorder(TreeNode* node,string& result){
        
        result += to_string(node->val) + ',';
        if(node->left){
            inorder(node->left,result);
        }else{
            result += "*,";
        }
        if(node->right){
            inorder(node->right,result);
        }else{
            result += "*,";
        }
    }
    
    int inorder_d(vector<string>& data, TreeNode* node,int idx){
        int next = idx + 1;
        
        if(data[next] != "*"){
            node->left = new TreeNode(stoi(data[next]));
            next = inorder_d(data,node->left,next);
        }else{
            next++;
        }
        
        if(data[next] != "*"){
            node->right = new TreeNode(stoi(data[next]));
            next = inorder_d(data,node->right,next);
        }else{
            next++;
        }
        
        return next;
        
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string ret = "";
        inorder(root,ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        vector<string> value = split(data,','); 
        if(value.empty()){
            return 0;
        }
        TreeNode* root = new TreeNode(stoi(value[0]));
        inorder_d(value,root,0);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;