//https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> all_paths;  // to store all paths in string format for output
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> cur_path; // store int values of the nodes in current path
        get_paths(root, cur_path); // call recursive function
        return all_paths; 
    }
    
    void get_paths(TreeNode* cur_root, vector<int> cur_path) {
        cur_path.push_back(cur_root->val); // append current nodes value to current path
        if(!cur_root->left && !cur_root->right) {  // if this is a leaf node, the current path is over so copy it to all_paths
            string pathstr = "";
            for(int i=0;i<cur_path.size();i++) {  // parse the path from root node to leaf node
                pathstr += to_string(cur_path[i]);  // convert integer values to string and create a string of current path
                if(cur_path.size()-i > 1)  // if it is not the last node in the path
                    pathstr += "->";
            }
            all_paths.push_back(pathstr); // insert the current path string into all_paths
        }
        else {  // if it is not a leaf node
            if(cur_root->left) // if left child exists
                get_paths(cur_root->left, cur_path); // call the function to fill up the paths for all branches in the left subtree
            if(cur_root->right)
                get_paths(cur_root->right, cur_path); // call the function to fill up the paths for all branches in the right subtree
        }
        
    }
};
