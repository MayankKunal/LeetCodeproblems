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
    int help(TreeNode*root,int&ans)
    {
        if(!root) return 0;
        int leftSum=max(0,help(root->left,ans));
        int rightSum=max(0,help(root->right,ans));
        ans=max(ans,root->val+leftSum+rightSum);
        return max(root->val+leftSum,root->val+rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        
        
        int ans=INT_MIN;

        help(root,ans);
        return ans;
    }
};