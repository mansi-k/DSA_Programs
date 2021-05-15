// https://leetcode.com/problems/invert-binary-tree/

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
// Logic : swap left and right subtrees starting from leaf nodes
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode* tmp = new TreeNode();
        tmp = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = tmp;
        return root;
    }
};
