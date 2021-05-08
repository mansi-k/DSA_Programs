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
//Logic : We get the sums of subtrees and tilts of each node by recursing to the bottom of the tree (using DFS)
public:
    
    vector<int> all_tilts;
    
    int findTilt(TreeNode* root) {
        if (!root) // if tree is empty, return 0
            return 0;
        getTilt(root); // call recursive function
        return accumulate(all_tilts.begin(), all_tilts.end(), 0); // sum up all tilts and return
    }
    
    int getTilt(TreeNode* root) {
        if (!root) // if node is null return 0
            return 0;
        int left_sum = getTilt(root->left); // recursive call to get sum of all nodes in left subtree of current node
        int right_sum = getTilt(root->right); // recursive call to get sum of all nodes in right subtree of current node
        int tilt = abs(left_sum - right_sum); // calculate absolute difference to find tilt of the current node
        all_tilts.push_back(tilt); // push the tilt value of current node into all_tilts vector
        return (root->val + left_sum + right_sum); // return the sum of its value and both subtrees to the parent node
    }
};
