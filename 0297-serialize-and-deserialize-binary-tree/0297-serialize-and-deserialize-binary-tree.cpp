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
    // Encodes a tree to a single string.
    void dfs(TreeNode* root, string& s) {
        if (!root) {
            s += "null,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
    }
    string serialize(TreeNode* root) {
        string ans;
        dfs(root, ans);
        return ans;
    }
    TreeNode* buildTree(stringstream& ss) {

        string value;

        getline(ss, value, ',');

        if (value == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = buildTree(ss);

        root->right = buildTree(ss);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return buildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));