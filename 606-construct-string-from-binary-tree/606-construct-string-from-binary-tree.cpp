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
    
    string tree2str(TreeNode* root) 
    {
        string s="";
        
        if(!root) return s;
        
        //root
            s += to_string(root->val);
            
        //left
            if(root->left!=NULL)
            s += '(' + tree2str(root->left) + ')';
           else if(root->right!=NULL) s+="()";
            
        // right
            if(root->right!=NULL)
             s += '(' + tree2str(root->right) + ')';
             
        return s;
    }
};


//best 

// class Solution {
// public:
//     string s;
//     void con(TreeNode* root,string &s)
//     {
//         if(root==NULL)return;
//         s+=to_string(root->val);
//         if(!root->left && !root->right)
//         {
//             return;
//         }
//         s+='(';
//         con(root->left,s);
//         s+=')';
//         if(root->right)
//         {
//              s+='(';
//         con(root->right,s);
//         s+=')';
         
//         }
        
        
//     }
//     string tree2str(TreeNode* root) {
//         string s="";
//         con(root,s);
//         return s;
//     }
// };