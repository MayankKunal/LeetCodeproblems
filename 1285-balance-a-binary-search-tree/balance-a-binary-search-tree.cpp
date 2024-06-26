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
    void inOrder(TreeNode*root,vector<int>&arr)
    {
        if(!root) return;
        inOrder(root->left,arr);
        arr.push_back(root->val);
        inOrder(root->right,arr);
    }
    TreeNode*buildTree(vector<int>&arr,int s,int e)
    {
        while(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode*node=new TreeNode(arr[mid]);
        node->left=buildTree(arr,s,mid-1);
        node->right=buildTree(arr,mid+1,e);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int>arr;
           inOrder(root,arr);
           int s=0;
           int e=arr.size()-1;
           return buildTree(arr,s,e);

    }
};