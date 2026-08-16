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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n %2 == 0){
            return ans;
        }
        if(n == 1){
            ans.push_back(new TreeNode(0));
            return ans;
        }
        for(int left=1;left<n;left+=2){
            int right = n - left - 1;
            vector<TreeNode*>rightSubTree = allPossibleFBT(left);
            vector<TreeNode*>leftSubTree = allPossibleFBT(right);
            for(auto l : leftSubTree){
                for(auto r : rightSubTree){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};