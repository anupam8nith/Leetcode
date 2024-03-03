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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        ListNode* p=head,*pre=p;
        
        int size=0;
        while(p)
        {
            size++;
            p=p->next;
        }
        p=head;
        
        //if only one element
        if(size==1 && n==1)
        {
            ListNode *q=NULL;
            return q;
        }
        
        //if to delete head
        if(size==n)
        {
            p=p->next;
            return p;
        }
        
         //if to delete from middle or last
        int count=0;
        while(count!=size-n)
        {
            count++;
            p=p->next;
            
            if(count==size-n)
            {
                break;
            }
            pre=p;
        }
        
        pre->next=p->next;
        delete p;
        return head;
    }
};