// https://leetcode.com/problems/leaf-similar-trees/

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
// Logic : Use DFS on tree from lef to right order to get the leaves-sequence for each tree and then compare both sequences
public:
    vector<int> templeaves;
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeaves(root1);
        vector<int> leaves1 = templeaves;
        templeaves.clear();
        getLeaves(root2);
        if(leaves1 == templeaves)
            return true;
        return false;
    }
    
    void getLeaves(TreeNode* root) { // recursive DFS
        int nulls=0;
        if(root->left)
            getLeaves(root->left);
        else
            nulls++;
        if(root->right)
            getLeaves(root->right);
        else
            nulls++;
        if(nulls>=2)
            templeaves.push_back(root->val);
    }
};
