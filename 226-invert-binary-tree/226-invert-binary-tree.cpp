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
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) 
//     {
//         //recursive
//         if(!root)return NULL;
        
//         invertTree(root->left);
//         invertTree(root->right);
        
//         swap(root->left,root->right);
        
//         return root;
//     }
// };


//Iterative


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        stack<TreeNode*> st;        
        st.push(root);
        
        while(st.size() > 0){
            TreeNode* top = st.top();
            st.pop();
            
            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
            
            // swap the left & right child of parent node
            swap(top->left, top->right);
        }
        
        return root;
    }
};