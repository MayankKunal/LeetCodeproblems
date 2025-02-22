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
    TreeNode* recoverFromPreorder(string traversal) {
        
        int n=traversal.size();
        int count=0;
        string val="";
        int i=0;
        while(traversal[i]!='-' && i<n)
        {
              val+=traversal[i];
              i++;
        }
        TreeNode*root=new TreeNode(stoi(val));
        TreeNode*temp=root;

        map<int,TreeNode*>mp;
        
        mp[0]=root;
        for(;i<n;i++)
        {
            if(traversal[i]=='-')
            {
                count++;
            }
            else
            {
                cout<<count;
                string val="";
                while(traversal[i]!='-' && i<n)
                {
                  val+=traversal[i];
                  i++;
                }
                
                TreeNode*currNode=new TreeNode(stoi(val));
                
                // cout<<mp[count-1];
                TreeNode*parentNode=mp[count-1];
               cout<<count-1;
              if(parentNode->left==NULL)
              {
                parentNode->left=currNode;
              }
              else parentNode->right=currNode;
              mp[count]=currNode;
              count=1;
            }
        }

        return root;
          
    }
};