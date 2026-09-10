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
    int c = 0;
    int countNodes(TreeNode* root){
        if(!root)return 0;
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
    int total(TreeNode* root){
        if(!root) return 0;
        return root->val + total(root->left) + total(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int cnt = countNodes(root);
        int totali = total(root);
        int avg = totali/cnt;
        if(root->val == avg) c++;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return c;
    }
};