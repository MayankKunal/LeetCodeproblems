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
    int help(vector<int>&arr)
    {
        vector<int>v=arr;
        sort(arr.begin(),arr.end());
         unordered_map<int,int>mp;
         int n=arr.size();
      for(int i=0;i<n;i++)
      {
        mp[v[i]]=i;
      }   

       int count=0;

      for(int i=0;i<n;i++)
      {
        if(v[i]!=arr[i])
        {
            int curr=mp[arr[i]];
            mp[v[i]]=curr;
            swap(v[i],v[curr]);
            count++;
        }
      }
      return count;
    }
public:
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>q;
        int ans=0;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>arr;
            while(n--)
            {
                auto it=q.front();
                q.pop();
                arr.push_back(it->val);
                if(it->left)
                q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans+=help(arr);
        }
        return ans;
    }
};