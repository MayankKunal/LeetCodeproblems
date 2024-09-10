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
    int gcd(int a,int b)
    {
        
        if(b>a) swap(a,b);
            if(a%b==0) return b;
            return gcd(b,a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode*p1=head;
        ListNode*p2=head->next;
        while(p2!=NULL)
        {
            cout<<p1->val<<" "<<p2->val;
            int g=gcd(p1->val,p2->val);
            
            ListNode*temp=new ListNode(g);
            p1->next=temp;
            temp->next=p2;
            p1=p2;
            p2=p2->next;
        }
        return head;
    }
};