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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        int count=0;
        int prev=-1;
        while(head!=NULL&&head->next!=NULL)
        {
            if(prev!=-1 && head->val>prev && head->val>head->next->val)
            {
                    arr.push_back(count);
            }
            else if(prev!=-1 && head->val<prev && head->val<head->next->val)
            {
                arr.push_back(count);
            }
            count++;
            prev=head->val;
            head=head->next;
        }
        if(arr.size()<2) return {-1,-1};
        sort(arr.begin(),arr.end());
      int n=arr.size();
      int maxDiff=arr[n-1]-arr[0];
      int minDiff=INT_MAX;
      for(int i=0;i<n-1;i++)
      {
        minDiff=min(minDiff,abs(arr[i+1]-arr[i]));
      }
      return {minDiff,maxDiff};
    }
};