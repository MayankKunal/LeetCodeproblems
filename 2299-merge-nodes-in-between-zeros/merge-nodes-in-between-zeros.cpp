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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode*temp=head;
        int value=0;
        ListNode*ans=NULL;
        ListNode*res=ans;
        while(temp!=NULL)
        {
            if(temp->val!=0)
            {
                value+=temp->val;  
            }
            else
            {       
                 if(value==0) ;
                      else if(res==NULL)
                      {
                        res=new ListNode(value);
                        ans=res;
                      }
                      else
                      {
                        res->next=new ListNode(value);
                        res=res->next;
                      }
                      value=0;
            }

            temp=temp->next;
        }
        return ans;
    }
};