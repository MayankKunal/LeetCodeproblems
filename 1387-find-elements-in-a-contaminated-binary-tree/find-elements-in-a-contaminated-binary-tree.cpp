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
class FindElements {
    unordered_set<int>st;
    void help(TreeNode*root,int val,unordered_set<int>&st)
    {
        if(root==NULL) return;
        st.insert(val);
        help(root->left,(2*val)+1,st);
        help(root->right,(2*val)+2,st);
    }
public:
    FindElements(TreeNode* root) {
        
        help(root,0,st);
    }
    
    bool find(int target) {
        
        if(st.find(target)!=st.end())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */