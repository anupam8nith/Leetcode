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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int count=0;
        ListNode *p=head,*newhead=NULL,*end=NULL;
        
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }

        if(count<=1 || k==0 || k%count==0)
            return head;
        
        int i=0;
        p=head;
        
        while(i!=count - k%count -1)
        {
        p=p->next;
        i++;
        }
    
        newhead=p->next;
    
        end=p;
        
        while(p->next!=NULL && p!=NULL)
            p=p->next;
        
        
        p->next=head;
        end->next=NULL;
        
        return newhead;
        
    }
};


// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) 
//     {
//         vector<int> v;
        
//         ListNode *p=head;
        
//         while(p!=NULL)
//         {
//             v.push_back(p->val);
//             p=p->next;
//         }
        
//         int n = size(v);
//         vector<int> v2(v);
        
//         for(int i=0;i<n;i++)
//             v[(i+k)%n]=v2[i];
        
//         p=head;
        
//         int i=0;
//         while(p!=NULL)
//         {
//             p->val = v[i++];
//             p=p->next;
//         }
        
//         return head;
//     }
// };