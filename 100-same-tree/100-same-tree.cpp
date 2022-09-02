/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p ^ !q)
            return false;
        if(p==q) return true;
        
        
        //BFS
        queue<pair<TreeNode*,TreeNode*>> kyu;
        kyu.push({p,q});
        
        
        while(!kyu.empty())
        {
            p= kyu.front().first;
            q= kyu.front().second;
            kyu.pop();
            
            if(p->val!=q->val) return false;
            if(!p->left ^ !q->left) return false;
            if(!p->right ^ !q->right) return false;
            
            
            if(p->left!=NULL && q->left!=NULL) kyu.push({p->left,q->left});
            if(p->right!=NULL && q->right!=NULL) kyu.push({p->right,q->right});
            
        }
    
        return true;
    }
};


// // Recursively
// bool isSameTree1(TreeNode* p, TreeNode* q) {
//     if (p && q)
//         return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     return p == q;
// }

// // BFS + queue
// bool isSameTree(TreeNode* p, TreeNode* q) {
//     queue<pair<TreeNode*, TreeNode*>> myQueue;
//     myQueue.push(pair<TreeNode*, TreeNode*>(p, q));
//     while (!myQueue.empty()) {
//         p = myQueue.front().first;
//         q = myQueue.front().second;
//         if(!p ^ !q || (p && q && p->val != q->val))
//             break;
//         myQueue.pop();
//         if(p && q) {
//             myQueue.push(pair<TreeNode*, TreeNode*>(p->left, q->left));
//             myQueue.push(pair<TreeNode*, TreeNode*>(p->right, q->right));
//         }
//     }
//     return myQueue.empty();
// }

// // DFS + stack
// bool isSameTree3(TreeNode* p, TreeNode* q) {
//     stack<pair<TreeNode*, TreeNode* >> myStack;
//     myStack.push(pair<TreeNode*, TreeNode*>(p, q));
//     while (!myStack.empty()) {
//         p = myStack.top().first;
//         q = myStack.top().second;
//         if (!p ^ !q || (p && q && p->val != q->val))
//             break;
//         myStack.pop();
//         if (p && q) {
//             myStack.push(pair<TreeNode*, TreeNode*> (p->right, q->right));
//             myStack.push(pair<TreeNode*, TreeNode*> (p->left, q->left));
//         }
//     }
//     return myStack.empty();
// }