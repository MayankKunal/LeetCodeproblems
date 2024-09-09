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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
       
       int row,col;
       int colStart=0,rowStart=0;
       m-=1;
       n-=1;
       while(rowStart<=m && colStart<=n)
       {       col=colStart;
            while(head!=NULL && col<=n)
            {
               ans[rowStart][col]=head->val;
               head=head->next;
               col++;       
            }
            rowStart++;
            row=rowStart;
            while(head!=NULL && row<=m)
            {
                ans[row][n]=head->val;
                head=head->next;
                   row++;
            }
            n--;
            col=n;
            while(head!=NULL && col>=colStart)
            {
                ans[m][col]=head->val;
                head=head->next;
                col--;
            }
            m--;
            row=m;
            while(head!=NULL && row>=rowStart)
            {
                ans[row][colStart]=head->val;
                head=head->next;
                row--;
            }
             colStart++;
       }
        return ans;
    }
};