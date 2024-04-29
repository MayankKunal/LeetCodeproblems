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
    TreeNode*help(int ps,int pe,vector<int>&postorder,int is,int ie,vector<int>&inorder,unordered_map<int,int>&inMap)
    {
        if(ps>=pe || is>=ie) return NULL;  
        int rootEle=postorder[pe-1];
        int rootIndex=inMap[rootEle];
        int leftSub=rootIndex-is;
        TreeNode*root=new TreeNode(rootEle);
        root->left=help(ps,ps+leftSub,postorder,is,rootIndex,inorder,inMap);
        root->right=help(ps+leftSub,pe-1,postorder,rootIndex+1,ie,inorder,inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>inMap;
        for(int i=0;i<n;i++)
        {
             inMap[inorder[i]]=i;
        }

        return help(0,n,postorder,0,n,inorder,inMap);
    }
};