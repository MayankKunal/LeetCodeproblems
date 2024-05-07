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
    ListNode* doubleIt(ListNode* head) {
        
        ListNode*curr=reverse(head);
        ListNode*dble=NULL;
    ListNode*ans=NULL;
    int carry=0;
        while(curr!=NULL)
        {
            int vl=curr->val;
          vl=((2*vl)+carry);
          carry=vl/10;
          int d=vl%10;
          if(dble==NULL)
          {
            dble=new ListNode(d);
            ans=dble;
          }
          else
          {
            dble->next=new ListNode(d);
            dble=dble->next;
          }
          curr=curr->next;
        }

        if(carry)
        {
            dble->next=new ListNode(carry);
            dble=dble->next;
        }

        ans=reverse(ans);
        return ans;
    }
};