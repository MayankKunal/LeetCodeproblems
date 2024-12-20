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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        bool reverse=false;
        while(!q.empty())
        {
            int n=q.size();
            vector<TreeNode*>arr(n);
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                if(reverse)
                {
                arr[i]=it;
                if(i>=n/2)
                {
                    swap(arr[i]->val,arr[n-i-1]->val);
                }
                }
            }
                reverse=!reverse;
            
        }

        return root;
    }
};