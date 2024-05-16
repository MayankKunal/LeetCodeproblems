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
    bool evaluateTree(TreeNode* root) {
        
        if(!root) return true;
        if(!root->left && !root->right)
        {
              return root->val;
        } 

        int symbol=root->val;
        if(symbol==2) return evaluateTree(root->left)|evaluateTree(root->right);

        return evaluateTree(root->right)&evaluateTree(root->left);
    }
};