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
    
    int avg(TreeNode* root, int sum,int nodes)
    {
        if(root==NULL) return 0;
        queue<TreeNode*> q;q.push(root);
        
        while(!q.empty())
        {
            TreeNode * temp= q.front();q.pop();
            sum+=temp->val;
            nodes++;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        return sum/nodes;
    }
    
    int averageOfSubtree(TreeNode* root) 
    {
        int count=0;
        
        if(root==NULL) return 0;
        queue<TreeNode*> q;q.push(root);
        
        while(!q.empty())
        {
            TreeNode * temp= q.front();q.pop();
            
            int val = avg(temp,0,0);
            if(val==temp->val)count++;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        return count;
    }
};