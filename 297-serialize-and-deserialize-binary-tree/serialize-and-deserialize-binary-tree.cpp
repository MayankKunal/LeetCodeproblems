/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans="";
        queue<TreeNode*>q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            string nodeVal="null";
            if(it!=NULL)
            {
            nodeVal=to_string(it->val);
            q.push(it->left);
             q.push(it->right);
            }
            ans+=nodeVal+',';
            
             
        }
        // ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*currNode=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="null")
            currNode->left=NULL;
            else
            {
                currNode->left=new TreeNode(stoi(str));
                q.push(currNode->left);
            }
            getline(s,str,',');
            if(str=="null")
            currNode->right=NULL;
            else
            {
                currNode->right=new TreeNode(stoi(str));
                q.push(currNode->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));