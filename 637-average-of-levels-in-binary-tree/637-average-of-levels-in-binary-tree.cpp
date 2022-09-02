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
    vector<double> averageOfLevels(TreeNode* root) 
    {
         vector<double> ans;
        
        //BFS
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
    
        
        TreeNode *node=NULL;
        
        double avg=0;
        
        while(!q.empty())
        {
            int n= q.size();
            avg=0;
            for(int i=0;i<n;i++)
            {
                node = q.front();
                q.pop();
                
                avg+= node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            avg/=n;
            ans.push_back(avg);
        }
        
        return ans;
        
    }
};