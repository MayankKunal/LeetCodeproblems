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
    ListNode*deleteHead(ListNode*head)
    {
        ListNode*temp=head->next;
        ListNode*currNode=head;
        delete currNode;
        head=temp;
        return head;
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int>st;
        for(int x:nums) st.insert(x);
        while(head!=NULL && st.find(head->val)!=st.end())
        {
            head=head->next;
        }
        ListNode*temp=head;
        ListNode*ans=NULL;
        ListNode*res;
        while(temp!=NULL)
        {
            if(st.find(temp->val)==st.end())
            {
                if(ans==NULL)
                {
                    ans=new ListNode(temp->val);
                    res=ans;
                }
                else
                {
                    ans->next=new ListNode(temp->val);
                    ans=ans->next;
                }
            }
            temp=temp->next;
        }
       
        return res;
    }
};