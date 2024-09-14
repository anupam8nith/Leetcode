class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Initialize the result vector with k null pointers
        vector<ListNode*> ans(k, nullptr);
        
        // Calculate the total length of the linked list
        ListNode* ptr = head;
        int n = 0;
        while (ptr != nullptr) {
            n++;
            ptr = ptr->next;
        }
        
        // Determine the size of each part
        int portionSize = n / k;
        int extra = n % k;  // Extra nodes to distribute across the first 'extra' parts
        
        // Reset the pointer to the head of the list
        ptr = head;
        ListNode* prev = nullptr;

        // Split the list into parts
        for (int i = 0; i < k; i++) {
            ans[i] = ptr;  // Start of the current part
            int currentPartSize = portionSize + (i < extra ? 1 : 0);  // Add 1 if we're in the first 'extra' parts
            
            // Traverse current part size and disconnect
            for (int j = 0; j < currentPartSize; j++) {
                prev = ptr;  // Keep track of the previous node
                ptr = ptr->next;
            }
            
            // Disconnect the current part from the next
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }
        
        return ans;
    }
};
