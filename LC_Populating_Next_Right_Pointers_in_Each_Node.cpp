// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    map<int,Node*> m; // maintain the last visited node per level

    void assignNext(Node* root,int level){
        if(root!=NULL){
            if(m[level])   
                (root)->next = m[level]; // connect
            m[level] = root;
            assignNext((root)->right,level+1);  // visit right child first
            assignNext((root)->left,level+1);
        }
    }

    Node* connect(Node* root) {
        assignNext(root,0);
        return root;
    }
};
