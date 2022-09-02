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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        
        //BFS
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool normal=1;
        while(!q.empty())
        {
            int n= q.size();
            vector<int> level(n);
            
            for(int i=0;i<n;i++)
            {
                TreeNode *curr= q.front();
                q.pop();
                
                if(normal==1)
                {
                    level[i]=curr->val;
                }
                else
                {
                    level[n-1-i]=curr->val;
                }
                
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            if(normal==1)
                normal=0;
            else
                normal=1;
            ans.push_back(level);
        }
        return ans;
        
    }
};