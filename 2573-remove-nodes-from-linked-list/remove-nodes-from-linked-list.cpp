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
    ListNode* reverse(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*nxt=NULL;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        
        stack<int>st;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            int value=curr->val;
            curr=curr->next;
            while(!st.empty() && st.top()<value)
            {
                st.pop();
            }
            st.push(value);
            
        }

ListNode*ans=NULL;
  ListNode*res;
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            if(ans==NULL)
            {
             ans=new ListNode(x);
             res=ans;
            }
            else 
            {
             ans->next=new ListNode(x);
             ans=ans->next;
            }
        }

        ListNode*r=reverse(res);
        return r;
    }
};