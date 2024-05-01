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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode*curr=new TreeNode(val);
            curr->left=root;
            return curr;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,2});
        while(!q.empty())
        {
             auto it=q.front();
             q.pop();
             TreeNode*curr=it.first;
             int d=it.second;
             if(d==depth)
             {
                TreeNode*tempLeft=NULL;
                TreeNode*tempRight=NULL;
                if(curr->left)
                {
                      tempLeft=curr->left;
                }
                if(curr->right)
                {
                    tempRight=curr->right;
                }
             TreeNode*newLeft=new TreeNode(val);
             TreeNode*newRight=new TreeNode(val);
             curr->left=newLeft;
             curr->right=newRight;
               newLeft->left=tempLeft;
               newRight->right=tempRight;
             q.push({newLeft,d+1});
             q.push({newRight,d+1});
             }
             else
             {
                if(curr->left)
                {
                    q.push({curr->left,d+1});
                }
                if(curr->right)
                {
                    q.push({curr->right,d+1});
                }
             }
        }
        return root;
    }
};