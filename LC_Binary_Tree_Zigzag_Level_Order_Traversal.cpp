// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> temp;
        vector<vector<int>> zigzag;
        if(!root)
            return zigzag;
        queue<TreeNode*> q; // bfs queue
        q.push(root);
        TreeNode* delim = new TreeNode(999); // delimiter node to indicate end of level
        q.push(delim);
        bool leftdir = true; // indicates left-to-right traversal
        TreeNode* curnode;
        while(!q.empty()) { // usual bfs
            curnode = q.front();
            q.pop();
            if(curnode == delim) { // if current level ended
                if(!leftdir) // if right-to-left
                    reverse(temp.begin(),temp.end()); // reverse the vector containing level nodes
                if(!temp.empty())
                    zigzag.push_back(temp);
                temp.clear();
                leftdir = !leftdir; // change the direction flag
                continue;
            }
            temp.push_back(curnode->val);
            if(curnode->left)
                q.push(curnode->left);
            if(curnode->right)
                q.push(curnode->right);
            if(q.front()==delim) {
                q.push(delim);
            }
        }
        return zigzag;
    }
};
