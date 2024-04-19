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
    int ans=0;
    
    void add(TreeNode* root, int temp)
    {
        temp*=10;temp+=root->val;
        if(!root->left && !root->right) ans+=temp;
        
        if(root->left)
        add(root->left,temp);
        if(root->right)
        add(root->right,temp);
    }
    
    
    int sumNumbers(TreeNode* root) 
    {
        
        add(root,0);
        return ans;   
    }
};