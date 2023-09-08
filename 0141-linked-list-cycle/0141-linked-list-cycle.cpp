/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head==NULL)
            return false;
        
       ListNode *fast=head->next, *slow=head;
        
        while(fast!=slow)
        {
            if(fast==NULL || slow==NULL)
                return false;
            else
            {
                fast=fast->next;
                
                if(fast==NULL)
                    return false;
                else
                fast=fast->next;
                
                slow=slow->next;
            }
            
        }
        
        return true;
    }
    
};