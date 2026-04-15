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
    int help(TreeNode*root,int &ans)
    {
        if(!root) return 0;
       
       int leftHeight=help(root->left,ans);
       int rightHeight=help(root->right,ans);
       ans=max(ans,leftHeight+rightHeight);

       return 1+max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans=0;
        help(root,ans);

        return ans;
    }
};