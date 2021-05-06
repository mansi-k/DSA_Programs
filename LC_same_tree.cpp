//https://leetcode.com/problems/same-tree/
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
// Logic: if any tree traversal method finds all nodes (including nulls) in the same order for both trees, then they are equal
// why include nulls? eg: X(root) --> X(right) and X(left) --> X(root) : all traversals [X,X] without nulls will say both trees are same 
public:
    vector<string> postorder_p, postorder_q; // to store postorders of both trees
    vector<string> temporder; // to use inside recursive function
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        get_postorder(p);
        postorder_p = temporder;
        temporder.clear();
        get_postorder(q);
        postorder_q = temporder;
        temporder.clear();
        if (postorder_p == postorder_q) // check if both orders are same, if yes then trees are equal
            return true;
        return false;
    }
    
    void get_postorder(TreeNode* root) { // left, root, right
        if (!root) {
            temporder.push_back("null");
            return;
        }
        get_postorder(root->left);
        get_postorder(root->right);
        temporder.push_back(to_string(root->val));
    }
};
