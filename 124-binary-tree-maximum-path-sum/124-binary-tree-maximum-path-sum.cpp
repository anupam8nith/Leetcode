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
    int maxi = INT_MIN;
    
    int sumcheck(TreeNode *root)
    {
        if(root==NULL) return 0;
        
        int lsum = max(0,sumcheck(root->left));
        int rsum = max(0,sumcheck(root->right));
        
        maxi = max(maxi, root->val + lsum + rsum);
        
        return root->val + max(lsum,rsum);
    }
    
    
    int maxPathSum(TreeNode* root) 
    {
        if(root==NULL) return 0;
        
        sumcheck(root);
        
        return maxi;
    }
};


//o(n) solution

// class Solution {
// public:
    
//     int path(TreeNode * root, int &maxi)
//     {
//         if(root==NULL) return 0;
        
//         int lsum = max(0,path(root->left,maxi));
//         int rsum = max(0,path(root->right,maxi));
        
//         maxi=max(maxi,lsum+rsum+root->val);
        
//         return root->val + max(lsum,rsum);
//     }
         
//     int maxPathSum(TreeNode* root) 
//     {
//         if(root==NULL)
//             return 0;
        
//         int maxi =INT_MIN;
        
//         path(root,maxi);
        
//         return maxi;
        
//     }
// };