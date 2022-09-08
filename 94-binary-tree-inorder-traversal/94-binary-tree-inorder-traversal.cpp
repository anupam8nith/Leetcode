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
        
    vector<int> inorderTraversal(TreeNode* root) 
    {
        //iterative approach
        vector<int> ans;
        
        if(root==NULL) return ans;
        
        stack<TreeNode *> st;
            
            while(root!= NULL || st.empty()!=1)
            {
                
                if(root!=NULL) 
                {
                    st.push(root);
                    root=root->left;
                }
                else
                {
                    root=st.top();
                    st.pop();
                    
                    ans.push_back(root->val);
                    root=root->right;
                }
               
            }
        
     return ans;
        
    }
};

 //iterative approach
        
//         vector<int> vi;
//         if(root==NULL) return vi;
        
//         stack<TreeNode*> st;
//         while(root!=NULL || st.empty()!=true)
//         {
//             if(root!=NULL)
//             {
//                 st.push(root);
//                 root=root->left;
//             }
//             else
//             {
//                 root=st.top();
//                 st.pop();
                
//                 vi.push_back(root->val);
//                 root=root->right;
//             }

//         }
        
//         return vi;



//recursive

//  void inorder(TreeNode *root, vector<int>&a)
//     {
//         if(root==NULL) return;
        
//         inorder(root->left,a);
//         a.push_back(root->val);
//         inorder(root->right,a);
//     }
        
//     vector<int> inorderTraversal(TreeNode* root) 
//     {
//         TreeNode *p = root;
        
//         vector<int> a;
//         if(p==NULL)
//             return a;
//         inorder(p, a);
//         return a;
//     }