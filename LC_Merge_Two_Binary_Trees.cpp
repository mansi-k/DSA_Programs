// https://leetcode.com/problems/merge-two-binary-trees/

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
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        root1 = traverse(root1,root2);
        return root1;
    }
    
    TreeNode* traverse(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) {
            return NULL;
        }
        if(root1 && root2) {
            TreeNode* tmp = new TreeNode();
            tmp->val = root1->val + root2->val;
            tmp->left = traverse(root1->left,root2->left);
            tmp->right = traverse(root1->right,root2->right);
            return tmp;
        }
        else if(root1 && !root2) {
            return root1;
        }
        else {
            return root2;
        }        
    }
};
