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
    
    void doSomething(queue<TreeNode*> &q, int sz, int &val)
    {
         
        for(int i=0;i<sz;i++)
        {
            TreeNode *curr = q.front(),*left = curr->left, *right = curr->right;

            curr->left = new TreeNode(val,left,nullptr);
            curr->right = new TreeNode(val,nullptr,right);
            
            q.pop();
        }    
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode *node = new TreeNode(val,root,NULL);
            return node;
        }
        queue<TreeNode*> q; q.push(root);
        int lvl=1;
        
        while(!q.empty() && lvl<=depth)
        {
            if(lvl==depth-1)
            {
                doSomething(q,q.size(),val);
                break;
            }
            
            int sz = q.size();
            
            for(int i=0;i<sz;i++)
            {
                TreeNode *curr = q.front();q.pop();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
           
            ++lvl;   
        }
        
        return root;
    }
};