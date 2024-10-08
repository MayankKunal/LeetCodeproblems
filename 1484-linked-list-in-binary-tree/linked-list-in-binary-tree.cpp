/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(TreeNode* root, ListNode* head) {
        if (head == nullptr) return true; // Reached the end of the list, so it's a match.
        if (root == nullptr) return false; // Reached a null node in the tree, so no match.

        if (root->val != head->val) return false; // Values do not match.

        // Recursively check both left and right subtree for the next node in the list.
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;

        // Start DFS from current node or recursively check left and right subtrees.
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};