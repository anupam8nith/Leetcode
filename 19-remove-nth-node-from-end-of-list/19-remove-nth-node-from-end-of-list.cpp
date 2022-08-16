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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* p=head,*pre=p;
        
        int size=0;
        while(p)
        {
            size++;
            p=p->next;
        }
        p=head;
        
        if(size==1 && n==1)
        {
            ListNode *q=NULL;
            return q;
        }
        
        if(size==n)
        {
            p=p->next;
            return p;
        }
        
        
        int count=0;
        while(count!=size-n)
        {
            p=p->next;
            count++;
            if(count==size-n)
            {
                break;
            }
            pre=p;
        }
        
        pre->next=p->next;
        
        return head;
    }
};