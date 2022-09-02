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
#include<list>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        //BFS
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode *curr=NULL;
        
        while(!q.empty())
        {
            int n = q.size();
            
            vector<int> level;
            
            for(int i=0;i<n;i++)
            {
                curr = q.front();
                q.pop();
                
                if(curr!=NULL)
                level.push_back(curr->val);
                
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};