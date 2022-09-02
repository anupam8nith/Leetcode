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
    
    int path(TreeNode * root, int &maxi)
    {
        if(root==NULL) return 0;
        
        int lsum = max(0,path(root->left,maxi));
        int rsum = max(0,path(root->right,maxi));
        
        maxi=max(maxi,lsum+rsum+root->val);
        
        return root->val + max(lsum,rsum);
    }
         
    int maxPathSum(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        
        int maxi =INT_MIN;
        path(root,maxi);
        
        return maxi;
        
    }
};