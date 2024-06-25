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
    void help(TreeNode*root,int &nodeSum)
    {
        if(!root) return;
        help(root->right,nodeSum);
        nodeSum+=root->val;
        root->val=nodeSum;
        help(root->left,nodeSum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        
        int nodeSum=0;
        help(root,nodeSum);
        return root;
    }
};