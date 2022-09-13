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
    void add(TreeNode* root, vector<string> &s,string str)
    {
        
        if(root->left==NULL && root->right==NULL) 
        {
            str+=to_string(root->val);
            s.push_back(str);
            // str="";
            return;
        }
        
        str += to_string(root->val) + "->";
        
        
        if(root->left!=NULL)
        add(root->left,s,str);
        if(root->right!=NULL)
        add(root->right,s,str);
        
        
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> s;
        if(root==NULL) return s;
        string str ;
            // str+= to_string(root->val) + "->";
        add(root,s,str);
        
        
        return s;
    }
};