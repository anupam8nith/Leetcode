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
    bool isSymmetric(TreeNode* root) 
    {
        if(root->left==NULL && root->right==NULL)
            return true ;
        
        TreeNode *p=root->left,*q=root->right;
        
        //iteratively using bfs
        
        if(!p ^ !q)
            return false;
        
        
        //BFS
        queue<pair<TreeNode*,TreeNode*>> kyu;
        kyu.push({p,q});
        
        
        while(!kyu.empty())
        {
            p= kyu.front().first;
            q= kyu.front().second;
            kyu.pop();
            
            if(p->val!=q->val) return false;
            if(!p->left ^ !q->right) return false;
            if(!p->right ^ !q->left) return false;
            
            
            if(p->left!=NULL && q->right!=NULL) kyu.push({p->left,q->right});
            if(p->right!=NULL && q->left!=NULL) kyu.push({p->right,q->left});
            
        }
        return true;
    }
};


//best iterative

// bool isSymmetric(TreeNode* root) {
        
//         if(!root)
//             return 1;
        
//         queue<TreeNode*> q;
//         q.push(root->left);
//         q.push(root->right);
        
//         while(!q.empty())
//         {
//             TreeNode *l,*r;
            
//             l=q.front();
//             q.pop();
            
//             r=q.front();
//             q.pop();
            
//             if(!l && !r)
//                 continue;
            
//             if(!l || !r || l->val!=r->val)
//                 return 0;
            
//             q.push(l->left);
//             q.push(r->right);
            
//             q.push(l->right);
//             q.push(r->left);
//         }
//         return 1;
//     }