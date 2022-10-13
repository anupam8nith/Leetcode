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
    ListNode* deleteMiddle(ListNode* head) 
    {
        int count=0,mid=0;
        ListNode *p = head,*q=nullptr;
        
        if(head->next==NULL)
        {
            head=NULL;
            return head;
        }
        
        while(p!=nullptr)
        {
            count++;
            p=p->next;
        }
        
        mid=floor(count/2);
        p=head;
        
        for(int i=0;i<mid-1;i++)
        {
            p=p->next;
        }
        
        if(p->next!=NULL)
        q= p->next->next;
        
        p->next = q;
        
        return head;
    }
};