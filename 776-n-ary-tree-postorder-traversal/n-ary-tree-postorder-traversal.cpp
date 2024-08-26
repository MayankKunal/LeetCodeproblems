/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void help(Node*root,vector<int>&ans)
    {
        if(!root) return;
        for(auto node:root->children)
        {
            help(node,ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        
        vector<int>ans;
        help(root,ans);
        return ans;
    }
};