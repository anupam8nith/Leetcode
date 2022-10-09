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
    
    void inorder(TreeNode * root, vector<int> &v)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> v;
        inorder(root,v);
        
        //we got sorted v
        
        if(v.size()==1) return false;
        
        
        for(auto x: v)
        {
            if(binary_search(v.begin(),v.end(),k-x) && k!=2*x)
                return true;
        }
        
        return false;
        
    }
};