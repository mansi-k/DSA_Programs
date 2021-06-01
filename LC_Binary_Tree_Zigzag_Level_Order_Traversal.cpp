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


// ****** Using Deque *******

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool isLTR = true;
        while(!dq.empty()) {
            int n = dq.size();
            vector<int> currLevel;
            if(isLTR) { // if left to right
                for(int i=0;i<n;i++) { // parse from queue front, and push childnodes left to right
                    auto curr = dq.front();
                    dq.pop_front();
                    currLevel.push_back(curr->val);
                    if(curr->left)
                        dq.push_back(curr->left);
                    if(curr->right)
                        dq.push_back(curr->right);
                }
                isLTR = false; // change direction flag
            } 
            else { // if right to left
                for(int i=0;i<n;i++) { // parse from queue tail, and push childnodes right to left
                    auto curr = dq.back(); 
                    dq.pop_back();
                    currLevel.push_back(curr->val);
                    if(curr->right)
                        dq.push_front(curr->right);
                    if(curr->left)
                        dq.push_front(curr->left);
                }
                isLTR = true; // change direction flag
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};
