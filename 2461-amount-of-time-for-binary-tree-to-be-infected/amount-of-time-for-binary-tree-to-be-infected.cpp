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
    TreeNode*findNode(TreeNode*root,int src)
    {
         queue<TreeNode*>q;
         q.push(root);
         while(!q.empty())
         {
            TreeNode*node=q.front();
            q.pop();
            if(node->val==src) return node;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
         }

         return NULL;
    }

    void findParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
                parent[node->right]=node;
            }
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        
           unordered_map<TreeNode*,TreeNode*>parent;
           findParent(root,parent);
          TreeNode*src=findNode(root,start);
          queue<pair<TreeNode*,int>>q;
          q.push({src,0});
          unordered_map<TreeNode*,int>vis;
         vis[src]=1;
         int ans=0;
          while(!q.empty())
          {
             auto it=q.front();
             q.pop();

             TreeNode*node=it.first;
             int time=it.second;
             ans=max(ans,time);

             if(parent[node] && !vis[parent[node]])
             {
                q.push({parent[node],time+1});
                vis[parent[node]]=1;
             }
             if(node->left && !vis[node->left])
             {
                q.push({node->left,time+1});
                vis[node->left]=1;
             }
             if(node->right && !vis[node->right])
             {
                q.push({node->right,time+1});
                vis[node->right]=1;
             }
          }

          return ans;


    }
};