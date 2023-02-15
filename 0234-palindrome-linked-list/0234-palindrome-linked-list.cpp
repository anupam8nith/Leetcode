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
    bool isPalindrome(ListNode* head)
    {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        ListNode* p=head;
        string s="";
        
        while(p!=NULL)
        {
            s+=(char)p->val;
            p=p->next;
            
        }
        
        int n=size(s);
        
        n--;
        
        int i=0;
        
        while(i<n)
            if(s[i++]!=s[n--])
                return false;
        
        return true;
        
        
        
    }
};