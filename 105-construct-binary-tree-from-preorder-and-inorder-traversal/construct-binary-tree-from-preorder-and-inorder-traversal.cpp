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
  TreeNode*helpBuildTree(int ps,int pe,vector<int>&preorder,int is,int ie,vector<int>&inorder,unordered_map<int,int>&inMap)
{
    if(ps>=pe || is>=ie) return NULL;
    int rootEle=preorder[ps];
    TreeNode*root=new TreeNode(rootEle);
    int rootIndex=inMap[rootEle];
  int leftSub=rootIndex-is;
    root->left=helpBuildTree(ps+1,ps+leftSub+1,preorder,is,rootIndex,inorder,inMap);
    root->right=helpBuildTree(ps+leftSub+1,pe,preorder,rootIndex+1,ie,inorder,inMap);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
          unordered_map<int,int>inMap;

          for(int i=0;i<n;i++)
          {
            inMap[inorder[i]]=i;
          }

        return helpBuildTree(0,n,preorder,0,n,inorder,inMap);
    }
};