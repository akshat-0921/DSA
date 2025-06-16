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
    ListNode* merge2Lists(ListNode* l1,ListNode* l2)
    {
        ListNode* temp=new ListNode(0);
        ListNode* li=temp;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                li->next=l1;
                l1=l1->next;
            }
            else {
                li->next=l2;
                l2=l2->next;
            }
            li=li->next;
        }
        if(l2!=NULL)
        {
            li->next=l2;
        }
        else li->next=l1;
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        if(k==1){
            return lists[0];
        }
        ListNode* ans=lists[0];
        for(int i=1;i<k;i++)
        {
            ans=merge2Lists(ans,lists[i]);
        }
        return ans;
    }
};