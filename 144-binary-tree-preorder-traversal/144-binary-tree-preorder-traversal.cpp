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
        vector<int> preorderTraversal(TreeNode* root) 
    {
    //iterative 
        vector<int> preorder;
        if(root==NULL) return preorder;
            
        stack<TreeNode*> st;
            
        st.push(root);
        
            while(!st.empty())
            {
                TreeNode* curr =st.top();
                st.pop();
                
                preorder.push_back(curr->val);
                
                if(curr->right!=NULL) st.push(curr->right);
                if(curr->left!=NULL) st.push(curr->left);
                
                
            }
        return preorder;
    }
};

//1. recursive
    
//     void pre(TreeNode* root, vector<int> &a)
//     {
//         if(root==NULL) return;
//         a.push_back(root->val);
//         pre(root->left,a);
//         pre(root->right,a);
//     }

//     vector<int> preorderTraversal(TreeNode* root) 
//     {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
//         vector<int> p;
//         pre(root,p);
//         return p;


//2. Morris (best approach)

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         while (root) {
//             if (root -> left) {
//                 TreeNode* pre = root -> left;
//                 while (pre -> right && pre -> right != root) {
//                     pre = pre -> right;
//                 }
//                 if (!pre -> right) {
//                     pre -> right = root;
//                     nodes.push_back(root -> val);
//                     root = root -> left;
//                 } else {
//                     pre -> right = NULL;
//                     root = root -> right;
//                 }
//             } else {
//                 nodes.push_back(root -> val);
//                 root = root -> right;
//             }
//         }
//         return nodes;
//     }
// };


//3. Iterative approach

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         stack<TreeNode*> todo;
//         while (root || !todo.empty()) {
//             if (root) {
//                 nodes.push_back(root -> val);
//                 if (root -> right) {
//                     todo.push(root -> right);
//                 }
//                 root = root -> left;
//             } else {
//                 root = todo.top();
//                 todo.pop();
//             }
//         }
//         return nodes;
//     }
// };