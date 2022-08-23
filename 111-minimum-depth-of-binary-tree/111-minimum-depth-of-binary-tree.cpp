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
    int minDepth(TreeNode* root) 
    {
        //fast io
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        if(root==NULL)
            return 0;
        
        int height=0;
        // code 
        queue<TreeNode*> q;
        q.push(root);
        
        //loop
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* curr_node = q.front();
                q.pop();
                if(curr_node->left==NULL && curr_node->right==NULL)
                    return height+1;
                if(curr_node->left!=NULL) q.push(curr_node->left);
                if(curr_node->right!=NULL) q.push(curr_node->right);
                
                
            }
            
            height++;
        }
        
        
        
        return height;
    }
};