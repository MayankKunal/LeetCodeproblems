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
public:
    vector<vector<int>> levelOrder(Node* root) {
     
        vector<vector<int>>res;
           if(!root) return res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp;
            while(n--)
            {
                  Node*currNode=q.front();
                  q.pop();
                  temp.push_back(currNode->val);
                  if(currNode->children.size()>0)
                  {
                  for(auto adjNode:currNode->children)
                  {
                    q.push(adjNode);
                  }
                  }
            }
            res.push_back(temp);
        }
        return res;
    }
};