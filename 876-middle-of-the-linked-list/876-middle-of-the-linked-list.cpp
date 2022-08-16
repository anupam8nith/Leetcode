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
    ListNode* middleNode(ListNode* head) 
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    
        ListNode* p=head;
        
        int count=0, target=0;
        while(p!=NULL)
        { 
            count++;
            p=p->next;
        }
        p=head;
        
        count = count/2 +1;
        
        while(target<count-1)
        {
            target++;
            p=p->next;
        }
        return p;
    }
};