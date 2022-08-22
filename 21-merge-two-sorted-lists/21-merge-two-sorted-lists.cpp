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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
        
        ListNode *p=list1, *q=list2;
        
        if(!p)
            return q;
        if(!q)
            return p;
        
        // both lists not null
        
        if(p->val<= q->val)
        {
            p->next= mergeTwoLists(p->next,q);
            return p;
        }
        else
        {
            q->next = mergeTwoLists(p,q->next);
            return q;
        }
       
    }
};